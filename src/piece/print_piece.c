/*
** print_piece.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Feb 26 14:13:02 2016 bougon_p
** Last update Sat Feb 27 23:21:46 2016 bougon_p
*/

#include "tetris.h"

void		aff_piece(t_arglist *tetri_ig)
{
  int		j;
  t_tetri	*tmp_to_print;

  tmp_to_print = tetri_ig->root->data;
  j = -1;
  while (++j < tmp_to_print->height)
    {
      mvprintw(j + POS_GAME_Y + tmp_to_print->pos_y,
	       POS_GAME_X + 1 + tmp_to_print->pos_x, tmp_to_print->item[j]);
    }
}
