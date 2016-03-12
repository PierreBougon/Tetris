/*
** game.c for GAME in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar  8 08:31:42 2016 bougon_p
** Last update Sat Mar 12 21:58:57 2016 bougon_p
*/

#include "tetris.h"

int	game(t_data *data)
{
  if ((data->refind = find_new_tetri(data, data->refind)) == -2)
    return (1);
  if (data->refind == -3)
    return (-3);
  aff_layout(data);
  if (data->boole == 0)
    if ((init_tabnext(data, data->tetri_ig.root->next->data)) == 1)
      return (1);
  aff_tetris(data);
  data->to_move = need_to_move(data, data->to_move);
  data->refind = need_to_stop(data, data->refind);
  check_full_line(data);
  return (0);
}

int	fonction(t_data *data)
{
  int	i;
  int	size_max;
  int	j;

  j = 0;
  size_max = 1;
  i = 0;
  while (data->opt.arg[i])
    {
      while (data->opt.arg[i][j])
	{
	  if (j > size_max)
	    size_max = j;
	  j++;
	}
      i++;
    }
  if ((data->key_to_set_game = malloc(size_max)) == NULL)
    return (1);
  return (0);
}
