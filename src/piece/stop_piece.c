/*
** stop_piece.c for stop in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Feb 28 00:52:14 2016 bougon_p
** Last update Sat Mar 12 21:54:16 2016 bougon_p
*/

#include "tetris.h"

void	push_item(t_data *data, t_tetri *itemdata)
{
  int	j;
  int	i;

  j = -1;
  while (++j < itemdata->height)
    {
      i = -1;
      while (++i < itemdata->width)
  	{
	  if (itemdata->item[j][i] == '*')
	    data->tab_game[j + itemdata->pos_y][i + itemdata->pos_x]
	      = itemdata->color;
  	}
    }
}

int	need_to_stop(t_data *data, int refind)
{
  t_tetri       *itemdata;

  itemdata = data->tetri_ig.root->data;
  if ((itemdata->pos_y + itemdata->height + 1
       == data->gamevar.win_height && refind == 0)
      || collision(itemdata, data->tab_game) == 1)
    {
      push_item(data, itemdata);
      return (1);
    }
  else
    return (0);
}
