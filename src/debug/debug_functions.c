/*
** debug_functions.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sat Mar  5 16:21:34 2016 Clémenceau Cedric
** Last update Sat Mar  5 22:28:35 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	map_size(t_data *data, char *enter)
{
  int	width;
  int	height;
  int	i;

  i = 0;
  while (enter[i] != ',' && enter[i] != '\0')
    i++;
  enter[i++] = '\0';
  height = my_getnbr(enter);
  width = my_getnbr(&enter[i]);
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
  if ((data->gamevar.level = my_getnbr(str)) == 1)
    return (1);
  return (0);
}

void	init_base(t_data *data)
{
  data->score.high_score = 0;
  data->gamevar.level = 1;
  data->gamevar.speed = 1;
}
