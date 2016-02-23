/*
** initlist.c for init in /home/bougon_p/rendu/CPE_2015_Pushswap
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Sun Nov 15 20:41:12 2015 Pierre Bougon
** Last update Fri Dec 11 18:53:42 2015 Pierre Bougon
*/

#include "select.h"

int		create_cdlist(t_arglist *arg, char *_name)
{
  if ((arg->root = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  arg->root->prev = arg->root;
  arg->root->next = arg->root;
  arg->root->name = _name;
  arg->root->b_under = 1;
  arg->root->b_high = 0;
  arg->length = 1;
  return (0);
}

int		add_first_cdl(t_arglist *arg, char *_name)
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
  elem->name = _name;
  elem->b_under = 0;
  elem->b_high = 0;
  arg->length++;
  return (0);
}

int	add_last_cdl(t_arglist *arg, char *_name)
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
  elem->name = _name;
  elem->b_under = 0;
  elem->b_high = 0;
  arg->length++;
  return (0);
}

int	init_cdlist(char **av, int ac, t_arglist *arg)
{
  int	i;

  i = 1;
  create_cdlist(arg, av[i++]);
  while (i < ac)
    {
      add_last_cdl(arg, av[i++]);
    }
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
