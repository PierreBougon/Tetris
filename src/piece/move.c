/*
** move.c for MOVES in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Feb 27 21:47:51 2016 bougon_p
** Last update Mon Feb 29 11:46:34 2016 bougon_p
*/

#include "tetris.h"

float	need_to_move(t_data *data, float to_move)
{
  t_tetri	*itemdata;

  itemdata = data->tetri_ig.root->data;
  if ((int)to_move > data->gamevar.speed
      && (itemdata->pos_y + itemdata->height + POS_GAME_Y
	  < POS_GAME_Y + data->gamevar.win_height)
      && collision(itemdata, data->tab_game) == 0)
    {
      data->tetri_ig.root->data->pos_y += 1;
      return (0.0);
    }
  else
    return (to_move + 0.0005);
}

int		drop(t_data *data, t_arglist *tetri_ig)
{
  t_tetri	*itemdata;

  itemdata = tetri_ig->root->data;
  if (itemdata->pos_y + itemdata->height + POS_GAME_Y + 3
      < POS_GAME_Y + data->gamevar.win_height)
    tetri_ig->root->data->pos_y += 4;
  return (0);
}

int     move_left(t_data *data, t_arglist *tetri_ig)
{
  t_tetri	*itemdata;

  data = data;
  itemdata = tetri_ig->root->data;
  if (itemdata->pos_x + POS_GAME_X
      > POS_GAME_X)
    tetri_ig->root->data->pos_x -= 1;
  return (0);
}

int     move_right(t_data *data, t_arglist *tetri_ig)
{
  t_tetri	*itemdata;

  itemdata = tetri_ig->root->data;
  if (itemdata->pos_x + itemdata->width + POS_GAME_X
      < POS_GAME_X + data->gamevar.win_width)
    tetri_ig->root->data->pos_x += 1;
  return (0);
}
