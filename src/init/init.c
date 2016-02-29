/*
** init.c for INIT TABS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Feb 24 00:50:18 2016 bougon_p
** Last update Mon Feb 29 20:46:53 2016 Clémenceau Cedric
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

void	load_tetriminos(char **tetrinext, WINDOW *sub_next)
{
  int	y;

  y = -1;
  while (tetrinext[++y])
    mvwprintw(sub_next, y + 1, 1, tetrinext[y]);
}

void	init_tabnext(t_data *data,  t_tetri *tetrinext)
{
  werase(data->sub_next);
  wborder(data->sub_next, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(data->sub_next, 0, 1, "Next");
  wattrset(data->sub_next, COLOR_PAIR(tetrinext->color));
  load_tetriminos(tetrinext->item, data->sub_next);
  wattroff(data->sub_next, COLOR_PAIR(tetrinext->color));
  wrefresh(data->sub_next);
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
