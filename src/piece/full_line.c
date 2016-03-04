/*
** full_line.c for LINE in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar  4 17:03:11 2016 bougon_p
** Last update Fri Mar  4 18:28:17 2016 bougon_p
*/

#include "tetris.h"

void	clean_line(t_data *data, int j, int bonus)
{
  int	i;

  i = -1;
  while (++i < data->gamevar.win_width)
    data->tab_game[j][i] = 0;
  while (--j >= 0)
    {
      i = 0;
      while (++i <= data->gamevar.win_width)
	data->tab_game[j + 1][i] = data->tab_game[j][i];
    }
  data->score.score += 10 * bonus * data->score.move_bonus;
}

void		check_full_line(t_data *data)
{
  int		bonus;
  int		j;
  int		i;

  j = -1;
  bonus = 1;
  while (++j < data->gamevar.win_height)
    {
      i = 0;
      while (++i <= data->gamevar.win_width)
	{
	  if (data->tab_game[j][i] == 0)
	    break;
	}
      if (i - 1 == data->gamevar.win_width)
      	clean_line(data, j, bonus++);
    }
}
