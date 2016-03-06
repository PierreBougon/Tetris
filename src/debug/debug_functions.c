/*
** debug_functions.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sat Mar  5 16:21:34 2016 Clémenceau Cedric
** Last update Sat Mar  5 17:59:32 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	map_size(t_data *data, char *enter)
{
  int	width;
  int	height;
  int	i;

  i = 0;
  while (enter[i] != ',')
    i++;
  width = my_getnbr(enter);
  i++;
  while (enter[i++]);
  height = my_getnbr(&enter[i]);
  data->gamevar.win_width = width;
  data->gamevar.win_height = height;
  return (0);
}

int	without_next(t_data *data, char *enter)
{
  enter = enter;
  data->boole = 1;
  return (0);
}

void	init_base(t_data *data)
{
  data->score.high_score = 0;
  data->gamevar.level = 1;
  data->gamevar.speed = 1;
  data->tab_game = init_tab_game(data->gamevar.win_height,
				 data->gamevar.win_width);
}
