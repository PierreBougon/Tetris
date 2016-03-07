/*
** fill_tetri.c for TETRI in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar  7 14:54:12 2016 bougon_p
** Last update Mon Mar  7 17:04:02 2016 bougon_p
*/

#include "tetris.h"

int	get_color(t_tetri *tetri, int i, char *buf, char *save)
{
  int	p;

  p = 0;
  while (buf[i] != 0)
    save[p] = buf[i++];
  if (check_save(save, tetri) == 1)
    return (1);
  if ((tetri->color = my_getnbr(save)) == -1)
    return (1);
  if (tetri->color > 7 || tetri->color < 1)
    tetri->error = true;
  return (i);
}

int	get_height(t_tetri *tetri, int i, char *buf, char *save)
{
  int	p;

  p = 0;
  while (buf[i] != 0 && buf[i] != ' ')
    save[p++] = buf[i++];
  if (check_save(save, tetri) == 1)
    return (1);
  if ((tetri->height = my_getnbr(save)) == -1)
    return (1);
  save = set_line_null(save, 4096);
  return (i);
}

int	get_width(t_tetri *tetri, int i, char *buf, char *save)
{
  int	p;

  p = 0;
  while (buf[i] != 0 && buf[i] != ' ')
    save[p++] = buf[i++];
  if (check_save(save, tetri) == 1)
    return (1);
  if ((tetri->width = my_getnbr(save)) == -1)
    return (1);
  save = set_line_null(save, 4095);
  return (i);
}

void	check_item(t_tetri *tetri, int i)
{
  if (tetri->item[i] == NULL)
    tetri->error = true;
  if (tetri->item[i] != NULL)
    epurendstr(tetri->item[i]);
  if (tetri->item[i] == NULL || my_strlen(tetri->item[i]) > tetri->width)
    tetri->error = true;
}

void	parse_file(t_tetri *tetri, int fd)
{
  int	i;

  i = -1;
  while (++i < tetri->height)
    {
      if ((tetri->item[i] = get_next_line(fd)) == NULL)
        tetri->error = true;
      check_item(tetri, i);
    }
  if (i > tetri->height)
    tetri->error = true;
}
