/*
** init_tabgame.c for TABGAME in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar  3 08:42:06 2016 bougon_p
** Last update Thu Mar  3 12:07:08 2016 bougon_p
*/

#include "tetris.h"

void	set_null(int *linetab, int cols)
{
  int	i;

  i = -1;
  while (++i < cols)
    {
      linetab[i] = 0;
    }
}

int	**init_tab_game(int lines, int cols)
{
  int	j;
  int	**tab;

  j = -1;
  if ((tab = malloc(sizeof(int *) * lines + 1)) == NULL)
    return (NULL);
  tab[lines] = NULL;
  while (++j < lines)
    if ((tab[j] = malloc(sizeof(int) * cols)) == NULL)
      return (NULL);
  j = -1;
  while (++j < lines)
    set_null(tab[j], cols);
  return (tab);
}
