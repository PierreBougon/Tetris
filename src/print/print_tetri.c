/*
** print_tetri.c for print in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar  3 10:30:28 2016 bougon_p
** Last update Thu Mar  3 12:09:18 2016 bougon_p
*/

#include "tetris.h"

void	aff_all_tetris(int **tab, t_gamevar *gv, WINDOW *win)
{
  int	j;
  int	i;

  j = -1;
  while (++j < gv->win_height)
    {
      i = -1;
      while (++i <= gv->win_width)
  	{
  	  wattrset(win, COLOR_PAIR(tab[j][i]));
  	  if (tab[j][i] >= 1 && tab[j][i] <= 7)
            mvwaddch(win, j, i, '*');
  	  wattroff(win, COLOR_PAIR(tab[j][i]));
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
