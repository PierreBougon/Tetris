/*
** error.c for ERROR in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 18:56:41 2016 bougon_p
** Last update Fri Mar  4 20:02:46 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	my_putstr_err(char *str)
{
  endwin();
  write(2, str, my_strlen(str));
  return(1);
}

int	config(t_data *data)
{
  noecho();
  data->keys = init_keys();
  init_keytab(&data->tabkey);
  nodelay(data->win, TRUE);
  if (has_colors() == FALSE)
    {
      endwin();
      return (my_putstr_err("Your terminal does not support color\n"), 1);
    }
  srand(time(0));
  start_color();
  my_init_color();
  curs_set(0);
  main_loop(data);
  return (0);
}
