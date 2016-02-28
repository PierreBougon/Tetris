/*
** init.c for INIT TABS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Feb 24 00:50:18 2016 bougon_p
** Last update Sun Feb 28 03:01:13 2016 bougon_p
*/

#include "tetris.h"

char	**init_tab(int line, int col)
{
  char  **tab;
  int   i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (NULL);
  tab[line] = NULL;
  while (i < line)
    {
      if ((tab[i] = malloc(sizeof(char) * (col + 1))) == NULL)
        return (NULL);
      tab[i][col] = 0;
      i++;
    }
  return (tab);
}

void	init_tabgame(char **tabgame)
{
  int	j;

  j = 0;
  my_strcpy(tabgame[0], "------------");
  while (++j < 21)
    my_strcpy(tabgame[j], "|          |");
  my_strcpy(tabgame[21], "------------");
}
