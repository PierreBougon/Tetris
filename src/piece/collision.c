/*
** collision.c for collisions in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar  3 13:53:44 2016 bougon_p
** Last update Sun Mar  6 20:47:25 2016 Clémenceau Cedric
*/

#include "tetris.h"

int		collision_drop(t_tetri *itemdata, int **tab_game, int p)
{
  int           i;
  int		n;
  int		k;

  k = itemdata->height;
  while (--k >= 0)
    {
      i = -1;
      while (++i < itemdata->width)
	{
	  n = -1;
	  while (++n <= p)
	    {
	      if (itemdata->item[k][i] == '*'
		  && tab_game[itemdata->pos_y + k + 1 + n]
		  [i + itemdata->pos_x] >= 1
		  && tab_game[itemdata->pos_y + k + 1 + n]
		  [i + itemdata->pos_x] <= 7)
		return (1);
	    }
	}
    }
  return (0);
}

int		collision_right(t_tetri *itemdata, int **tab_game)
{
  int           j;

  j = -1;
  while (++j < itemdata->height)
    {
      if (itemdata->item[j][itemdata->width - 1] == '*'
          && tab_game[j + itemdata->pos_y][itemdata->pos_x + itemdata->width] >= 1
          && tab_game[j + itemdata->pos_y][itemdata->pos_x + itemdata->width] <= 7)
        return (1);
    }
  return (0);
}

int		collision_left(t_tetri *itemdata, int **tab_game)
{
  int           j;

  j = -1;
  while (++j < itemdata->height)
    {
      if (itemdata->item[j][0] == '*'
          && tab_game[j + itemdata->pos_y][itemdata->pos_x - 1] >= 1
          && tab_game[j + itemdata->pos_y][itemdata->pos_x - 1] <= 7)
        return (1);
    }
  return (0);
}

int		collision(t_tetri *itemdata, int **tab_game)
{
  int           i;
  int		n;

  n = itemdata->height;
  while (--n >= 0)
    {
      i = -1;
      while (++i < itemdata->width)
	{
	  if (itemdata->item[n][i] == '*'
	      && tab_game[itemdata->pos_y + n + 1]
	      [i + itemdata->pos_x] >= 1
	      && tab_game[itemdata->pos_y + n + 1]
	      [i + itemdata->pos_x] <= 7)
	    return (1);
	}
    }
  return (0);
}
