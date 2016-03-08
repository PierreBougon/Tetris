/*
** key_to_do.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Tue Mar  8 01:28:53 2016 Clémenceau Cedric
** Last update Tue Mar  8 02:16:54 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	keys_for_left(t_data *data, char *entered)
{
  my_strcpy(data->key[0], entered);
  return (0);
}

int	keys_for_turn(t_data *data, char *entered)
{
  my_strcpy(data->key[2], entered);
  return (0);
}

int	keys_for_right(t_data *data, char *entered)
{
  my_strcpy(data->key[1], entered);
  return (0);
}

int	keys_for_drop(t_data *data, char *entered)
{
  my_strcpy(data->key[3], entered);
  return (0);
}

int	keys_for_pause(t_data *data, char *entered)
{
  my_strcpy(data->key[5], entered);
  return (0);
}

int	keys_for_quit(t_data *data, char *entered)
{
  my_strcpy(data->key[4], entered);
  return (0);
}
