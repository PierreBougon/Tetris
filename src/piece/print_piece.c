/*
** print_piece.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Feb 26 14:13:02 2016 bougon_p
** Last update Fri Feb 26 20:12:38 2016 bougon_p
*/

#include "tetris.h"

void		aff_piece(t_arglist *tetri_ig)
{
  int		j;
  int		i;
  t_tetri	*tmp_to_print;

  endwin();


  tmp_to_print = tetri_ig->root->data;
  j = -1;
  i = (rand() % (19 - tmp_to_print->width)) + 1;
  while (++j < tmp_to_print->height)
    {
      mvprintw(j + 2, POS_GAME + i, tmp_to_print->item[j]);
    }
}
