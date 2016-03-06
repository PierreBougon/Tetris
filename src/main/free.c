/*
** free.c for FREE in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar  4 13:50:01 2016 bougon_p
** Last update Sun Mar  6 15:50:13 2016 Clémenceau Cedric
*/

#include "tetris.h"

void	my_free_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}
