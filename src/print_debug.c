/*
** print_debug.c for DEBUG in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 25 21:16:32 2016 bougon_p
** Last update Fri Feb 26 02:33:29 2016 bougon_p
*/

#include "tetris.h"

void	print(t_tetri *tmp)
{
  /* int	i; */
  int	j;

  j = 0;
  printf("ITEM HEIGHT = %d\n", tmp->height);
  while (j < tmp->height)
    {
      printf("%s\n", tmp->item[j++]);
    }
}

void		print_tetri(t_arglist *tetriminos)
{
  int		i;
  t_cdlist	*tmp;

  i = 0;
  tmp = tetriminos->root;
  printf("DANS LE PRINT L1 DE ITEM = %s\n", tetriminos->root->data->item[1]);
  printf("LIST LENGTH = %d\n", tetriminos->length);
  while (i++ < tetriminos->length)
    {
      print(tmp->data);
      tmp = tmp->next;
    }
}
