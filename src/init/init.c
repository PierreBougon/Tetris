/*
** init.c for INIT TABS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Feb 24 00:50:18 2016 bougon_p
** Last update Mon Feb 29 01:31:13 2016 Clémenceau Cedric
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

void	init_tabgame_base(char **tabgame)
{
  int	j;

  j = 0;
  my_strcpy(tabgame[0], "------------");
  while (++j < 21)
    my_strcpy(tabgame[j], "|          |");
  my_strcpy(tabgame[21], "------------");
}

void	init_tabnext(char **tabgame)
{
  my_strcpy(tabgame[0], "/Next--\\");
  my_strcpy(tabgame[1], "|      |");
  my_strcpy(tabgame[2], "|      |");
  my_strcpy(tabgame[3], "\\------/");
}

void	init_tabscore(char **tabscore)
{
  my_strcpy(tabscore[0] , "/------------------\\");
  my_strcpy(tabscore[1], "|                  |");
  my_strcpy(tabscore[2], "| High Score       |");
  my_strcpy(tabscore[3], "| Score            |");
  my_strcpy(tabscore[4], "|                  |");
  my_strcpy(tabscore[5], "| Lines            |");
  my_strcpy(tabscore[6], "| Level            |");
  my_strcpy(tabscore[7], "|                  |");
  my_strcpy(tabscore[8], "| Timer:           |");
  my_strcpy(tabscore[9], "\\------------------/");
}
