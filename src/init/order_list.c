/*
** order_list.c for ORDER in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 10 19:35:55 2016 bougon_p
** Last update Thu Mar 10 21:18:33 2016 bougon_p
*/

#include "tetris.h"

void		swap(t_cdlist *elem1, t_cdlist *elem2, t_arglist *arg)
{
  t_cdlist	*tmp;
  t_cdlist	*tmp2;

  tmp = elem1->prev;
  tmp2 = elem2->next;
  elem2->next = elem1;
  elem2->prev = tmp;
  elem1->next = tmp2;
  elem1->prev = elem2;
  tmp->next = elem2;
  tmp2->prev = elem1;
  if (elem1 == arg->root)
    arg->root = elem2;
}

int		order_list(t_arglist *arg)
{
  t_cdlist	*tmp;
  int		cmp;
  int		i;

  i = 0;
  tmp = arg->root;
  while (i + 1 < arg->length)
    {
      cmp = my_strcmp(tmp->data->name, tmp->next->data->name);
      while (cmp == 0 && i + 1 < arg->length)
	{
	  i++;
	  tmp = tmp->next;
	  cmp = my_strcmp(tmp->data->name, tmp->next->data->name);
	}
      if (cmp > 0)
	{
	  swap(tmp, tmp->next, arg);
	  tmp = arg->root;
	  i = 0;
	}
      else if (cmp < 0)
	{
	  tmp = tmp->next;
	  i++;
	}
    }
  return (0);
}
