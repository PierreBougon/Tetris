/*
** free.c for FREE in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar  4 13:50:01 2016 bougon_p
** Last update Wed Mar 16 18:17:25 2016 Clémenceau Cedric
*/

#include "tetris.h"

void	my_free_tab_int(int **tab_to_free)
{
  int   i;

  i = 0;
  while (i < 20) // le 20 a modifié par le data->gamevar_win_height ?
    free(tab_to_free[i++]);
  free(tab_to_free);
}

void	free_all(t_data *data, int ac)
{
  if (ac > 1)
    {
      if (data->opt.entered_key != NULL)
	free(data->opt.entered_key);
      my_free_tab(data->opt.key_to_set);
      my_free_tab(data->opt.to_check);
      my_free_tab(data->opt.arg);
      free(data->tetris_tab);
    }
  my_free_tab(data->key);
  my_free_tab(data->score.tab_score);
  my_free_tab_int(data->tab_game);
  free(data->key_to_set_game);
}

void	my_free_tab(char **tab_to_free)
{
  int   i;

  i = 0;
  while (tab_to_free[i] != NULL)
    free(tab_to_free[i++]);
  free(tab_to_free);
}
