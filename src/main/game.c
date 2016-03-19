/*
** game.c for GAME in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 18 13:32:33 2016 bougon_p
** Last update Fri Mar 18 13:44:32 2016 bougon_p
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

int	fonction(t_data *data, int to_malloc)
{
  int	i;
  int	j;

  j = -1;
  i = 0;
  if (to_malloc > 0)
    while (data->opt.arg[++i + 1])
      {
	while (data->opt.arg[i][++j])
	  {
	    if (j > to_malloc)
	      to_malloc = j;
	  }
      }
  if (to_malloc <= 6)
    {
      if ((data->key_to_set_game = malloc(sizeof(char) * 7)) == NULL)
	return (1);
    }
  else
    if ((data->key_to_set_game =
	 malloc(sizeof(char) * (to_malloc + 1))) == NULL)
      return (1);
  return (0);
}
