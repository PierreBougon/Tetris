/*
** print_piece.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Feb 26 14:13:02 2016 bougon_p
** Last update Mon Feb 29 20:05:21 2016 bougon_p
*/

#include "tetris.h"

void		aff_piece(WINDOW *win, t_arglist *tetri_ig)
{
  int		i;
  int		j;
  t_cdlist	*tmp;
  t_tetri	*tmp_to_print;

  tmp = tetri_ig->_root;
  i = 0;
  while (i++ < tetri_ig->length - 1)
    {
      tmp_to_print = tmp->data;
      j = -1;
      wattrset(win, COLOR_PAIR(tmp_to_print->color));
      while (++j < tmp_to_print->height)
	{
	  mvwprintw(win, tmp_to_print->pos_y + j,
		    tmp_to_print->pos_x, tmp_to_print->item[j]);
	}
      wattroff(win, COLOR_PAIR(tmp_to_print->color));
      tmp = tmp->prev;
    }
  dprintf(2, "\n\n\n");
  wrefresh(win);
}
