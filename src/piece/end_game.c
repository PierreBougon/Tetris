/*
** end_game.c for END in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Mar  6 00:09:29 2016 bougon_p
** Last update Sun Mar  6 00:25:28 2016 bougon_p
*/

#include "tetris.h"

int		check_end_game(t_data *data)
{
  t_tetri	*itemdata;
  int		i;
  int		j;

  itemdata = data->tetri_ig.root->data;
  j = itemdata->pos_y - 1;
  while (++j < itemdata->pos_y + itemdata->height)
    {
      i = itemdata->pos_x - 1;
      while (++i < itemdata->pos_x + itemdata->width)
	{
	  if (data->tab_game[j][i] >= 1
	      && data->tab_game[j][i] <= 7)
	    return (1);
	}
    }
  return (0);
}
