/*
** next.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Wed Mar  2 18:22:53 2016 Clémenceau Cedric
** Last update Thu Mar  3 12:49:56 2016 Clémenceau Cedric
*/

#include "tetris.h"

void	boole_next(t_data *data, char *str)
{
  str = str;
  data->boole = 1;
}

void	aff_keys(t_data *data)
{
  data = data;
  my_putstr("Key Left : ");
  my_putstr(data->key[0]);
  write(1, "\n", 1);
  my_putstr("Key Right : ");
  my_putstr(data->key[1]);
  write(1, "\n", 1);
  my_putstr("Key Turn : ");
  my_putstr(data->key[2]);
  write(1, "\n", 1);
  my_putstr("Key Drop : ");
  my_putstr(data->key[3]);
  write(1, "\n", 1);
  my_putstr("Key Quit : ");
  my_putstr(data->key[4]);
  write(1, "\n", 1);
  my_putstr("Key Pause : ");
  my_putstr(data->key[5]);
  write(1, "\n", 1);
}

void		my_show_list(t_arglist *list)
{
  t_cdlist	*tmp;
  int		i;
  int		n;

  tmp = list->root;
  n = 0;
  while (n++ < list->length)
    {
      i = 0;
      my_putstr("Tetriminos : Name ");
      my_putstr(tmp->data->name);
      my_putstr(" : Size ");
      my_put_nbr(tmp->data->width);
      write(1, "*", 1);
      my_put_nbr(tmp->data->height);
      my_putstr(" : Color ");
      my_put_nbr(tmp->data->color);
      write(1, " :\n", 3);
      while (tmp->data->item[i])
	{
	  my_putstr(tmp->data->item[i++]);
	  my_putstr("\n");
	}
      tmp = tmp->next;
    }
}

void	aff_tetriminos(t_data *data)
{
  my_putstr("Tetriminos : ");
  my_put_nbr(data->tetriminos.length);
  write(1, "\n", 1);
  my_show_list(&data->tetriminos);
}

void	aff_next(t_data *data)
{
  my_putstr("Next : ");
  if (data->boole == 0)
    my_putstr("Yes\n");
  else
    my_putstr("No\n");
}
