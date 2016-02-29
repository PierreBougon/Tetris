/*
** move.c for MOVES in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Feb 27 21:47:51 2016 bougon_p
** Last update Mon Feb 29 20:17:19 2016 bougon_p
*/

#include "tetris.h"

float	need_to_move(t_data *data, float to_move)
{
  t_tetri	*itemdata;

  itemdata = data->tetri_ig._root->data;
  if ((int)to_move > data->gamevar.speed
      && (itemdata->pos_y + itemdata->height
	  < data->gamevar.win_height))
      /* && collision(itemdata, data->tab_game) == 0) */
    {
      data->tetri_ig._root->data->pos_y += 1;
      return (0.0);
    }
  else
    return (to_move + 0.0005);
}

int		drop(t_data *data, t_arglist *tetri_ig)
{
  t_tetri	*itemdata;

  itemdata = tetri_ig->_root->data;
  if (itemdata->pos_y + itemdata->height + 4
      < data->gamevar.win_height)
    tetri_ig->_root->data->pos_y += 4;
  return (0);
}

int     move_left(t_data *data, t_arglist *tetri_ig)
{
  t_tetri	*itemdata;

  data = data;
  itemdata = tetri_ig->_root->data;
  if (itemdata->pos_x > 1)
    tetri_ig->_root->data->pos_x -= 1;
  return (0);
}

int     move_right(t_data *data, t_arglist *tetri_ig)
{
  t_tetri	*itemdata;

  itemdata = tetri_ig->_root->data;
  if (itemdata->pos_x + itemdata->width < data->gamevar.win_width + 1)
    tetri_ig->_root->data->pos_x += 1;
  return (0);
}
