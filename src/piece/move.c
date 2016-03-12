/*
** move.c for MOVES in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Feb 27 21:47:51 2016 bougon_p
** Last update Sat Mar 12 22:22:36 2016 bougon_p
*/

#include "tetris.h"

float	need_to_move(t_data *data, float to_move)
{
  t_tetri	*itemdata;

  itemdata = data->tetri_ig.root->data;
  if (to_move > data->gamevar.speed
      && (itemdata->pos_y + itemdata->height < data->gamevar.win_height)
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
  int		n;
  t_tetri	*itemdata;

  itemdata = tetri_ig->root->data;
  n = 4;
  while (n > 0)
    {
      if (itemdata->pos_y + itemdata->height + n + 1
	  < data->gamevar.win_height
	  && collision_drop(itemdata, data->tab_game, n - 1) == 0)
	{
	  data->score.move_bonus += 10;
	  tetri_ig->root->data->pos_y += n;
	  return (0);
	}
      n--;
    }
  return (0);
}

int	move_left(t_data *data, t_arglist *tetri_ig)
 {
  t_tetri	*itemdata;

  data = data;
  itemdata = tetri_ig->root->data;
  if (itemdata->pos_x > 1
      && collision_left(itemdata, data->tab_game) == 0)
    tetri_ig->root->data->pos_x -= 1;
  return (0);
}

int	move_right(t_data *data, t_arglist *tetri_ig)
{
  t_tetri	*itemdata;

  itemdata = tetri_ig->root->data;
  if (itemdata->pos_x + itemdata->width < data->gamevar.win_width + 1
      && collision_right(itemdata, data->tab_game) == 0)
    tetri_ig->root->data->pos_x += 1;
  return (0);
}
