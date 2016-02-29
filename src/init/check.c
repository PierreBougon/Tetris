/*
** check.c for check in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Feb 29 16:38:59 2016 bougon_p
** Last update Mon Feb 29 17:07:51 2016 bougon_p
*/

#include "tetris.h"

void		check_max(t_data *data)
{
  t_cdlist	*tmp;
  int		i;
  int		maxx;
  int		maxy;

  tmp = data->tetriminos.root;
  maxx = 0;
  maxy = 0;
  while (i++ < data->tetriminos.length)
    {
      if (maxx < tmp->data->width)
	maxx = tmp->data->width;
      if (maxy < tmp->data->width)
	maxy = tmp->data->width;
      tmp = tmp->next;
    }
  data->gamevar.maxwidth = maxx;
  data->gamevar.maxheight = maxy;
}
