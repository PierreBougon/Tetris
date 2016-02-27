/*
** move.c for MOVES in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Feb 27 21:47:51 2016 bougon_p
** Last update Sat Feb 27 22:25:37 2016 bougon_p
*/

#include "tetris.h"

int     drop(t_data *data, t_arglist *tetri_ig)
{

  data = data;
  tetri_ig->root->data->pos_y += 1;
  return (0);
}

int     move_left(t_data *data, t_arglist *tetri_ig)
{

  data = data;
  tetri_ig->root->data->pos_x -= 1;
  return (0);
}

int     move_right(t_data *data, t_arglist *tetri_ig)
{

  data = data;
  tetri_ig->root->data->pos_x += 1;
  return (0);
}
