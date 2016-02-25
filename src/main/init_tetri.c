/*
** init_tetri.c for TETRIMINOS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 25 16:38:30 2016 bougon_p
** Last update Thu Feb 25 22:18:15 2016 bougon_p
*/

#include "tetris.h"

void		take_nbr(t_tetri *tetri, char *buf, char *save)
{
  int           i;
  int           p;

  i = 0;
  p = 0;
  while (buf[i] != 0 && buf[i] != ' ')
    save[p] = buf[i++];
  tetri->width = my_getnbr(save);
  save = set_line_null(save, 4095);
  p = 0;
  i++;
  while (buf[i] != 0 && buf[i] != ' ')
    save[p] = buf[i++];
  tetri->height = my_getnbr(save);
  save = set_line_null(save, 4096);
  p = 0;
  i++;
  while (buf[i] != 0)
    save[p] = buf[i++];
  tetri->color = my_getnbr(save);
}

int		fill_tetri_carac(t_tetri *tetri, int fd)
{
  char          *buf;
  char          *save;

  if ((buf = malloc(sizeof(char) * 4096)) == NULL)
    return (1);
  buf = set_line_null(buf, 4095);
  if ((save = malloc(sizeof(char) * 4096)) == NULL)
    return (1);
  save = set_line_null(save, 4095);
  if ((buf = get_next_line(fd)) == NULL)
    return (1);
  take_nbr(tetri, buf, save);
  return (0);
}

char	*get_path(char *full_path)
{
  full_path[0] = '.';
  full_path[1] = '/';
  full_path[2] = 't';
  full_path[3] = 'e';
  full_path[4] = 't';
  full_path[5] = 'r';
  full_path[6] = 'i';
  full_path[7] = 'm';
  full_path[8] = 'i';
  full_path[9] = 'n';
  full_path[10] = 'o';
  full_path[11] = 's';
  full_path[12] = '/';
  return (full_path);
}

int		fill_tetri(char *path, t_tetri *tetri)
{
  int           fd;
  int           i;
  char		*full_path;
  int		size;

  size = my_strlen(path) + 13 + 1;
  if ((full_path = malloc(sizeof(char) * size)) == NULL)
    return (1);
  full_path = set_line_null(full_path, size);
  full_path = get_path(full_path);
  full_path = my_strcat(full_path, path);
  if ((fd = open(full_path, O_RDONLY)) == -1)
    return (1);
  if ((fill_tetri_carac(tetri, fd)) == 1)
    return (1);
  i = -1;
  if ((tetri->item = init_tab(tetri->height, tetri->width)) == NULL)
    return (1);
  while (++i < tetri->height)
    {
      if ((tetri->item[i] = get_next_line(fd)) == NULL)
        return (1);
    }
  close(fd);
  return (0);
}

int	create_elem(int i, t_arglist *arg, t_tetri *tetri)
{
  if (i == 0)
    {
      if ((create_cdlist(arg, tetri)) == 1)
	return (1);
    }
  else
    {
      if ((add_last_cdl(arg, tetri)) == 1)
	return (1);
    }
  return (0);
}

int		init_tetriminos(t_arglist *arg)
{
  DIR           *dirp;
  struct dirent *dir;
  t_tetri       tetri;
  int           i;

  i = 0;
  if ((dirp = opendir("./tetriminos")) == NULL)
    return (1);
  while ((dir = readdir(dirp)) != NULL)
    {
      if (dir->d_name[0] != '.' && my_strcmp(dir->d_name, "..") != 0)
	{
          if ((fill_tetri(dir->d_name, &tetri)) == 1)
	    return (1);
          if ((create_elem(i, arg, &tetri)) == 1)
	    return (1);
          i = 1;
        }
    }
  closedir(dirp);
  return (0);
}
