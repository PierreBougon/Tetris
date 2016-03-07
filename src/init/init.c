/*
** init.c for INIT TABS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Feb 24 00:50:18 2016 bougon_p
** Last update Mon Mar  7 01:55:24 2016 Clémenceau Cedric
*/

#include "tetris.h"

char	**init_tab(int line, int col)
{
  char  **tab_to_malloc;
  int   i;

  i = 0;
  if ((tab_to_malloc = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (NULL);
  tab_to_malloc[line] = NULL;
  while (i < line)
    {
      if ((tab_to_malloc[i] = malloc(sizeof(char) * (col + 1))) == NULL)
        return (NULL);
      tab_to_malloc[i][col] = 0;
      i++;
    }
  return (tab_to_malloc);
}

int	load_tetriminos(char **tetrinext, WINDOW *sub_next)
{
  int	y;

  y = -1;
  while (tetrinext[++y])
    if ((mvwprintw(sub_next, y + 1, 1, tetrinext[y])) == ERR)
      return (1);
  return (0);
}

int	init_tabnext(t_data *data,  t_tetri *tetrinext)
{
  if ((werase(data->sub_next)) == ERR)
    return (1);
  if (wborder(data->sub_next, '|', '|', '-', '-', '/', '\\', '\\', '/') == ERR)
    return (1);
  if ((mvwprintw(data->sub_next, 0, 1, "Next")) == ERR)
    return (1);
  if ((wattrset(data->sub_next, COLOR_PAIR(tetrinext->color))) == ERR)
    return (1);
  if ((load_tetriminos(tetrinext->item, data->sub_next)) == 1)
    return (1);
  if ((wattroff(data->sub_next, COLOR_PAIR(tetrinext->color))) == ERR)
    return (1);
  if ((wrefresh(data->sub_next)) == ERR)
    return (1);
  return (0);
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
