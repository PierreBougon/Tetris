/*
** key_event.c for KEYS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar  4 16:54:29 2016 bougon_p
** Last update Sun Mar  6 20:47:56 2016 Clémenceau Cedric
*/

#include "tetris.h"

int		get_key(t_data *data, int key, int *keys, t_tabkey *tab_game)
{
  int           i;

  i = 0;
  if (data->pause == true && key != keys[5])
    return (time_pause(data));
  while (key != keys[i])
    {
      i++;
      if (i > 5)
        return (0);
    }
  return (tab_game->tabkey[i](data, &data->tetri_ig));
}
