/*
** put_str_key.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Thu Mar  3 10:54:38 2016 Clémenceau Cedric
** Last update Thu Mar  3 19:15:26 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	config_key(t_data *data)
{
  int	i;

  i = 0;
  if ((data->key = init_tab(6, 8)) == NULL)
    return (1);
  my_strcpy(data->key[0], "^[[D");
  my_strcpy(data->key[1], "^[[C");
  my_strcpy(data->key[2], "^[[A");
  my_strcpy(data->key[3], "^[[B");
  my_strcpy(data->key[4], "27");
  my_strcpy(data->key[5], " ");
  while (data->key[i])
    {
      if ((my_strcmp(data->key[i], " ")) == 0)
	my_strcpy(data->key[i], "(space)");
      if ((my_strcmp(data->key[i], "27")) == 0)
	my_strcpy(data->key[i], "(escape)");
      i++;
    }
  return (0);
}


void	my_putstr_keys(t_data *data)
{
  data = data;
  my_putstr("-kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_putstr("-kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_putstr("-kt --key-turn={K}\tTurn tetrimino with key K\n");
  my_putstr("-kd --key-drop={K}\tSet default DROP on key K\n");
  my_putstr("-kq --key-quit={K}\tQuit program when press key K\n");
  my_putstr("-kp --key-pause={K}\tPause and restart game when press key K\n");
}

void	protect_me(t_data *data)
{
  int	maxx;
  int	maxy;

  maxx = getmaxx(data->win);
  maxy = getmaxy(data->win);
  if (maxx < data->gamevar.win_width + 50)
    while ((maxx = getmaxx(data->win)) < (data->gamevar.win_width + 50))
      {
	maxy = getmaxy(data->win);
	mvprintw(maxy / 2, ((maxx / 2) - 7),  "Window too short");
	refresh();
	erase();
      }
  if (maxy < data->gamevar.win_height + 10)
    while ((maxy = getmaxy(data->win)) < (data->gamevar.win_height + 10))
      {
	maxx = getmaxx(data->win);
	mvprintw(maxy / 2, ((maxx / 2) - 7),  "Window too short");
	refresh();
	erase();
      }
}
