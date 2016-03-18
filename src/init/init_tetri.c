/*
** init_tetri.c for TETRIMINOS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 25 16:38:30 2016 bougon_p
** Last update Fri Mar 18 19:18:49 2016 bougon_p
*/

#include "tetris.h"

int		take_nbr(t_tetri *tetri, char *buf, char *save)
{
  int           i;

  i = 0;
  i = get_width(tetri, i, buf, save);
  i++;
  i = get_height(tetri, i, buf, save);
  i++;
  if ((i = get_color(tetri, i, buf, save)) == -1)
    tetri->color = true;
  return (0);
}

int		fill_tetri_carac(t_tetri *tetri, int fd, char *name)
{
  char		*buf;
  char		*save;

  if ((save = malloc(sizeof(char) * 4096)) == NULL)
    return (1);
  save = set_line_null(save, 4095);
  if ((tetri->name = malloc(my_strlen(name) + 1)) == NULL)
    return (1);
  my_strcpy(tetri->name, name);
  change_extens(tetri->name);
  if ((buf = get_next_line(fd)) == NULL)
    return (1);
  if (take_nbr(tetri, buf, save) == 1)
    return (1);
  free(buf);
  free(save);
  return (0);
}

int		fill_tetri(char *path, t_tetri *tetri)
{
  int           fd;
  char		*full_path;
  int		size;

  size = my_strlen(path) + 13 + 1;
  if ((full_path = malloc(sizeof(char) * size)) == NULL)
    return (1);
  full_path = set_line_null(full_path, size);
  my_strcpy(full_path, "./tetriminos/");
  full_path = my_strcat(full_path, path);
  if ((fd = open(full_path, O_RDONLY)) == -1)
    return (1);
  if ((fill_tetri_carac(tetri, fd, path)) == 1)
    return (1);
  if ((tetri->item = init_tab(tetri->height, tetri->width)) == NULL)
    return (1);
  parse_file(tetri, fd);
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
  t_tetri       *tetri;
  int           i;

  arg->length = 0;
  if ((i = 0) || (dirp = opendir("./tetriminos")) == NULL)
    return (1);
  while ((dir = readdir(dirp)) != NULL)
    {
      if (my_strcmp(dir->d_name, ".") != 0 && my_strcmp(dir->d_name, "..") != 0
	  && check_name(dir->d_name) == 0)
	{
	  if ((tetri = malloc(sizeof(t_tetri))) == NULL)
	    return (1);
	  tetri->error = false;
          if ((fill_tetri(dir->d_name, tetri) == 1 ||
	       create_elem(i, arg, tetri)) == 1)
	    return (1);
          i = 1;
        }
    }
  if (arg->length == 0)
    exit_no_tetri();
  return (order_list(arg), closedir(dirp), 0);
}
