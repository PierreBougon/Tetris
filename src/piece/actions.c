/*
** actions.c for ACTIONS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Feb 27 19:05:39 2016 bougon_p
** Last update Sun Mar  6 00:05:04 2016 bougon_p
*/

#include "tetris.h"

char	**init_new(t_tetri *itemdata)
{
  char		**new;
  int		size;

  size = (itemdata->height > itemdata->width)
    ? itemdata->height : itemdata->width;
  new = init_tab(size, size);
  return (new);
}

void	fill_new_item(t_tetri *itemdata,
		      char **new, int n, int p)
{
  itemdata->item = new;
  itemdata->width = n;
  itemdata->height = p;
}

int		turn_tetri(t_data *data, t_arglist *tetri_ig)
{
  int		i;
  int		j;
  int		p;
  int		n;
  t_tetri	*itemdata;
  char		**new;

  itemdata = tetri_ig->root->data;
  if (itemdata->pos_x + itemdata->height - 1 > data->gamevar.win_width)
    return (0);
  new = init_new(itemdata);
  i = -1;
  p = 0;
  while (++i < itemdata->width)
    {
      n = 0;
      j = itemdata->height;
      while (--j >= 0)
	new[p][n++] = itemdata->item[j][i];
      p++;
    }
  my_free_tab(itemdata->item);
  fill_new_item(itemdata, new, n, p);
  return (0);
}
