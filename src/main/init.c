/*
** init.c for INIT TABS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Feb 24 00:50:18 2016 bougon_p
** Last update Wed Feb 24 14:40:45 2016 bougon_p
*/

#include "tetris.h"

char	***init_3dtab()
{
  if ((tetri = malloc(sizeof(char **))) == NULL)
    return (NULL);
}

char		***init_tetriminos()
{
  char		***tetri;
  DIR		*dirp;
  struct dirent	*dir;

  if ((tetri = init_3dtab()) == NULL)
    return (NULL);
  if ((dirp = opendir("./tetriminos")) == NULL)
    return (NULL);
  while ((dir = readdir(dirp)) != NULL)
    {
      if (dir->d_name[0] != '.' && my_strcmp(dir->d_name, "..") != 0)
	{
	  endwin();

	}
    }
  closedir(dirp);
  return (tetri);
}

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
      if ((tab[i] = malloc(sizeof(char) * col + 1)) == NULL)
        return (NULL);
      tab[col] = 0;
      i++;
    }
  return (tab);
}
