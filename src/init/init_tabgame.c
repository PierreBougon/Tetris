/*
** init_tabgame.c for TABGAME in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar  3 08:42:06 2016 bougon_p
** Last update Sat Mar 12 22:19:59 2016 bougon_p
*/

#include "tetris.h"

void	set_null(int *linetab, int cols)
{
  int	i;

  i = -1;
  while (++i < cols)
    linetab[i] = 0;
}

int	**init_tab_game(int my_lines, int my_cols)
{
  int	j;
  int	**tab_to_malloc;

  j = -1;
  if ((tab_to_malloc = malloc(sizeof(int *) * (my_lines + 2))) == NULL)
    return (NULL);
  tab_to_malloc[my_lines] = NULL;
  while (++j < my_lines + 1)
    if ((tab_to_malloc[j] = malloc(sizeof(int) * (my_cols + 1))) == NULL)
      return (NULL);
  j = -1;
  while (++j < my_lines + 1)
    set_null(tab_to_malloc[j], my_cols + 1);
  return (tab_to_malloc);
}

int	do_sub(t_data *data)
{
  if ((data->sub_win =
       subwin(data->win, data->gamevar.win_height,
	      data->gamevar.win_width + 2, 1, POS_GAME_X)) == NULL)
    return (1);
  if (data->boole == 0)
    if ((data->sub_next = subwin(data->win, (data->gamevar.maxheight >= 4) ?
				 data->gamevar.maxheight + 2 : 5,
				 (data->gamevar.maxwidth >= 7) ?
				 data->gamevar.maxwidth + 2 : 8, 1, POS_GAME_X +
				 data->gamevar.win_width + 5)) == NULL)
      return (1);
  return (0);
}
