/*
** check.c for check in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Feb 29 16:38:59 2016 bougon_p
** Last update Wed Mar 16 18:26:59 2016 bougon_p
*/

#include "tetris.h"

void	change_extens(char *name)
{
  int	i;

  i = my_strlen(name);
  while (name[--i] != 0 && name[i] != '.' );
  name[i] = 0;
}

void		check_max(t_data *data)
{
  t_cdlist	*tmp;
  int		i;
  int		maxx;
  int		maxy;

  tmp = data->tetriminos.root;
  maxx = 0;
  maxy = 0;
  i = 0;
  while (i++ < data->tetriminos.length)
    {
      if (maxx < tmp->data->width)
	maxx = tmp->data->width;
      if (maxy < tmp->data->height)
	maxy = tmp->data->height;
      tmp = tmp->next;
    }
  data->gamevar.maxwidth = maxx;
  data->gamevar.maxheight = maxy;
}
