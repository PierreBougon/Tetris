/*
** collision.c for collisions in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar  3 13:53:44 2016 bougon_p
** Last update Thu Mar  3 14:34:15 2016 bougon_p
*/

#include "tetris.h"

int		collision_drop(t_tetri *itemdata, int **tab)
{
  int           i;
  int		n;

  i = -1;
  while (++i < itemdata->width)
    {
      n = -1;
      while (++n <= 3)
	{
	  if (itemdata->item[itemdata->height - 1][i] == '*'
	      && tab[itemdata->pos_y + itemdata->height + n]
	      [i + itemdata->pos_x] >= 1
	      && tab[itemdata->pos_y + itemdata->height + n]
	      [i + itemdata->pos_x] <= 7)
	    return (1);
	}
    }
  return (0);
}

int		collision_right(t_tetri *itemdata, int **tab)
{
  int           j;

  j = -1;
  while (++j < itemdata->height)
    {
      if (itemdata->item[j][itemdata->width - 1] == '*'
          && tab[j + itemdata->pos_y][itemdata->pos_x + itemdata->width] >= 1
          && tab[j + itemdata->pos_y][itemdata->pos_x + itemdata->width] <= 7)
        return (1);
    }
  return (0);
}

int		collision_left(t_tetri *itemdata, int **tab)
{
  int           j;

  j = -1;
  while (++j < itemdata->height)
    {
      if (itemdata->item[j][0] == '*'
          && tab[j + itemdata->pos_y][itemdata->pos_x - 1] >= 1
          && tab[j + itemdata->pos_y][itemdata->pos_x - 1] <= 7)
        return (1);
    }
  return (0);
}

int		collision(t_tetri *itemdata, int **tab)
{
  int           i;

  i = -1;
  while (++i < itemdata->width)
    {
      if (itemdata->item[itemdata->height - 1][i] == '*'
          && tab[itemdata->pos_y + itemdata->height][i + itemdata->pos_x] >= 1
          && tab[itemdata->pos_y + itemdata->height][i + itemdata->pos_x] <= 7)
        return (1);
    }
  return (0);
}
