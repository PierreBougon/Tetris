/*
** tetri_error.c for ERROR in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Mar  6 16:24:23 2016 bougon_p
** Last update Sun Mar  6 16:56:36 2016 bougon_p
*/

#include "tetris.h"

char	*get_extens(char *name)
{
  int	i;
  char	*extens;

  i = my_strlen(name);
  while (name[--i] != '.' && i >= 0);
  extens = &name[i];
  return (extens);
}

int	check_name(t_tetri *tetri)
{
  char	*extens;

  extens = get_extens(tetri->name);
  if (my_strcmp(extens, ".tetrimino") != 0)
    {
      tetri->error = true;
    }
  else
    tetri->error = false;
  return (0);
}
