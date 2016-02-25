/*
** initlist.c for LIST in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 25 16:45:28 2016 bougon_p
** Last update Thu Feb 25 22:19:21 2016 bougon_p
*/

#include "tetris.h"
#include "list.h"

int		create_cdlist(t_arglist *arg, void *_data)
{
  if ((arg->root = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  arg->root->prev = arg->root;
  arg->root->next = arg->root;
  arg->root->data = _data;
  arg->length = 1;
  return (0);
}

int		add_first_cdl(t_arglist *arg, void *_data)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  if (arg->root != NULL)
    {
      elem->prev = arg->root;
      elem->next = arg->root->next;
      arg->root->next->prev = elem;
      arg->root->next = elem;
    }
  elem->data = _data;
  arg->length++;
  return (0);
}

int	add_last_cdl(t_arglist *arg, void *_data)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  if (arg->root != NULL)
    {
      elem->prev = arg->root->prev;
      elem->next = arg->root;
      arg->root->prev->next = elem;
      arg->root->prev = elem;
    }
  elem->data = _data;
  printf("ICI DANS LE ADD LAST L1 DE ITEM ROOT = %s\n", arg->root->data->item[1]);
  printf("ICI DANS LE ADD LAST L1 DE ITEM = %s\n", elem->data->item[1]);
  printf("ICI DANS LE ADD LAST L1 DE ITEM NEXT = %s\n", elem->next->data->item[1]);
  arg->length++;
  return (0);
}

int		free_list(t_arglist *arg)
{
  int		i;
  t_cdlist	*tmp;
  t_cdlist	*tmp2;

  i = 0;
  tmp2 = arg->root;
  while (i < arg->length)
    {
      tmp = tmp2;
      tmp2 = tmp->next;
      free(tmp);
      i++;
    }
  return (0);
}
