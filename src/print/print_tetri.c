/*
** print_tetri.c for print in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar  3 10:30:28 2016 bougon_p
** Last update Sun Mar  6 20:46:33 2016 Clémenceau Cedric
*/

#include "tetris.h"

void	aff_all_tetris(int **map, t_gamevar *gv, WINDOW *win)
{
  int	j;
  int	i;

  j = -1;
  while (++j < gv->win_height)
    {
      i = -1;
      while (++i <= gv->win_width)
  	{
  	  wattrset(win, COLOR_PAIR(map[j][i]));
  	  if (map[j][i] >= 1 && map[j][i] <= 7)
            mvwaddch(win, j, i, '*');
  	  wattroff(win, COLOR_PAIR(map[j][i]));
  	}
    }
  wrefresh(win);
}

int	aff_tetris(t_data *data)
{
  aff_piece(data->sub_win, &data->tetri_ig);
  aff_all_tetris(data->tab_game, &data->gamevar, data->sub_win);
  return (0);
}
