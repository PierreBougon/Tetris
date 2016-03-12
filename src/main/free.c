/*
** free.c for FREE in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar  4 13:50:01 2016 bougon_p
** Last update Sat Mar 12 15:17:39 2016 Clémenceau Cedric
*/

#include "tetris.h"

void	free_all(t_data *data, int ac)
{
  if (ac > 1)
    {
      my_free_tab(data->opt.key_to_set);
      my_free_tab(data->opt.to_check);
      my_free_tab(data->opt.arg);
      free(data->tetris_tab);
    }
  my_free_tab(data->key);
  my_free_tab(data->score.tab_score);
}

void	my_free_tab(char **tab_to_free)
{
  int   i;

  i = 0;
  while (tab_to_free[i] != NULL)
    free(tab_to_free[i++]);
  free(tab_to_free);
}
