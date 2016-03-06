/*
** init_tabgame.c for TABGAME in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar  3 08:42:06 2016 bougon_p
** Last update Sun Mar  6 20:45:46 2016 Clémenceau Cedric
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
  if ((tab_to_malloc = malloc(sizeof(int *) * (my_lines + 1))) == NULL)
    return (NULL);
  tab_to_malloc[my_lines] = NULL;
  while (++j < my_lines)
    if ((tab_to_malloc[j] = malloc(sizeof(int) * (my_cols + 1))) == NULL)
      return (NULL);
  j = -1;
  while (++j < my_lines)
    set_null(tab_to_malloc[j], my_cols + 1);
  return (tab_to_malloc);
}
