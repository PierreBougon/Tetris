/*
** debug_functions.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sat Mar  5 16:21:34 2016 Clémenceau Cedric
** Last update Fri Mar 11 15:29:02 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	map_size(t_data *data, char *enter)
{
  int	width;
  int	height;
  int	i;

  dprintf(2, "maxwidth = %d, maxheight = %d\n", data->gamevar.maxwidth, data->gamevar.maxheight);
  dprintf(2, "winwidth = %d, winheight = %d\n", data->gamevar.win_width, data->gamevar.win_height);
  i = 0;
  while (enter[i] != ',' && enter[i] != '\0')
    i++;
  enter[i++] = '\0';
  if ((height = my_getnbr(enter)) == -1)
    return (my_putstr("Bad map size\n"), -1);
  if ((width = my_getnbr(&enter[i])) == -1)
    return (my_putstr("Bad map size\n"), -1);
  if (width <= data->gamevar.maxwidth + 1 && height <= data->gamevar.maxheight + 1)
    return (my_putstr("Bad map size\n"), -1);
  data->gamevar.win_width = width;
  data->gamevar.win_height = height;
  return (0);
}

int	without_next(t_data *data, char *str)
{
  str = str;
  data->boole = 1;
  return (0);
}

int	level(t_data *data, char *str)
{
  if ((data->gamevar.level = my_getnbr(str)) == -1)
    return (my_putstr("Bad level insert\n"), 1);
  return (0);
}

void	init_base(t_data *data)
{
  data->gamevar.win_width = 10;
  data->gamevar.win_height = 20;
  data->score.high_score = 0;
  data->gamevar.level = 1;
  data->gamevar.speed = 1;
}
