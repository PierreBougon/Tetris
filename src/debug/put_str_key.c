/*
** put_str_key.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Thu Mar  3 10:54:38 2016 Clémenceau Cedric
** Last update Mon Mar  7 17:06:22 2016 bougon_p
*/

#include "tetris.h"

int	config_key(t_data *data)
{
  int	i;

  i = 0;
  if ((data->key = init_tab(6, 8)) == NULL)
    return (1);
  my_strcpy(data->key[0] ,tigetstr("kcub1"));
  my_strcpy(data->key[1] ,tigetstr("kcuf1"));
  my_strcpy(data->key[2] ,tigetstr("kcuu1"));
  my_strcpy(data->key[3] ,tigetstr("kcud1"));
  /* my_strcpy(data->key[0], "^[[D"); */
  /* my_strcpy(data->key[1], "^[[C"); */
  /* my_strcpy(data->key[2], "^[[A"); */
  /* my_strcpy(data->key[3], "^[[B"); */
  my_strcpy(data->key[4], "q");
  my_strcpy(data->key[5], " ");
  while (data->key[i])
    {
      if ((my_strcmp(data->key[i], " ")) == 0)
	my_strcpy(data->key[i], "(space)");
      i++;
    }
  return (0);
}


void	my_putstr_keys(t_data *data)
{
  data = data;
  my_putstr("  -kl --key-left={K}\t Move tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}\t Move tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}\t Turn tetrimino with key K\n");
  my_putstr("  -kd --key-drop={K}\t Set default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}\t Quit program when press key K\n");
  my_putstr("  -kp --key-pause={K}\t Pause and restart game when press key K\n");
}

int	get_it(t_data *data, int maxx, int maxy, int bol)
{
  if (bol == 0)
    {
      if ((maxy = getmaxy(data->win)) == ERR)
	return (1);
    }
  else
    if ((maxx = getmaxx(data->win)) == ERR)
      return (1);
  if ((mvprintw(maxy / 2, ((maxx / 2) - 7),  "Window too short")) == ERR)
    return (1);
  if ((refresh()) == ERR)
    return (1);
  if ((erase()) == 1)
    return (1);
  usleep(10);
  return (0);
}

int	protect_me(t_data *data)
{
  int	maxx;
  int	maxy;

  maxx = getmaxx(data->win);
  maxy = getmaxy(data->win);
  if (maxx < data->gamevar.win_width + 50)
    while ((maxx = getmaxx(data->win)) < (data->gamevar.win_width + 50))
      if ((get_it(data, maxx, maxy, 0)) == 1)
	return (1);
  if (maxy < data->gamevar.win_height + 10)
    while ((maxy = getmaxy(data->win)) < (data->gamevar.win_height + 10))
      if ((get_it(data, maxx, maxy, 1)) == 1)
	return (1);
  return (0);
}
