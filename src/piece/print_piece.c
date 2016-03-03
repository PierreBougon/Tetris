/*
** print_piece.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Feb 26 14:13:02 2016 bougon_p
** Last update Thu Mar  3 11:37:32 2016 bougon_p
*/

#include "tetris.h"

void		aff_piece(WINDOW *win, t_arglist *tetri_ig)
{
  int		j;
  int		n;
  t_tetri	*tmp;

  tmp = tetri_ig->root->data;
  j = -1;
  wattrset(win, COLOR_PAIR(tmp->color));
  while (++j < tmp->height)
    {
      n = -1;
      while (++n < tmp->width)
	{
	  if (tmp->item[j][n] == '*')
	    mvwaddch(win, tmp->pos_y + j,
		     tmp->pos_x + n, tmp->item[j][n]);
	}
    }
  wattroff(win, COLOR_PAIR(tmp->color));
}
