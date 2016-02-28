/*
** stop_piece.c for stop in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Feb 28 00:52:14 2016 bougon_p
** Last update Sun Feb 28 03:57:42 2016 bougon_p
*/

#include "tetris.h"

void		push_item(t_data *data)
{
  int		i;
  int		j;
  int		p;
  int		n;
  t_tetri       *itemdata;

  itemdata = data->tetri_ig.root->data;
  j = itemdata->pos_y - 1;
  p = 0;
  while (++j < itemdata->pos_y + itemdata->height)
    {
      n = 0;
      i = itemdata->pos_x - 1;
      while (++i < itemdata->pos_x + itemdata->width)
	{
	  if (itemdata->item[p][n] != ' ')
	    data->tab_game[j + 1][i + 1] = itemdata->item[p][n];
	  n++;
	}
      p++;
    }
}

int	need_to_stop(t_data *data)
{
  t_tetri       *itemdata;

  itemdata = data->tetri_ig.root->data;
  if (itemdata->pos_y + itemdata->height + POS_GAME_Y
      == POS_GAME_Y + data->gamevar.win_height)
    {
      push_item(data);
      return (1);
    }
  else
    return (0);
}
