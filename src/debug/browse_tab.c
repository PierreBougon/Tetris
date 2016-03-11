/*
** browse_tab.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sat Mar  5 22:07:39 2016 Clémenceau Cedric
** Last update Thu Mar 10 20:31:18 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	check_all_option(t_data *data, int *i, int *j)
{
  if ((my_strcmp(data->opt.arg[(*i)], data->opt.to_check[1])) == 0 ||
      (my_strcmp(data->opt.arg[(*i)], data->opt.to_check[2])) == 0)
    return (2);
  if ((my_strcmp(data->opt.arg[(*i)], data->opt.to_check[(*j)])) == 0)
    {
      if ((data->tetris_tab[(*j)](data, data->opt.key_to_set[*i])) == 1)
	return (1);
      if ((*j) == 8 || (*j) == 10 || (*j) == 12 || (*j) == 14 ||
	  (*j) == 16 || (*j) == 18)
	(*i)++;
      return (2);
    }
  (*j)++;
  return (0);
}

int	browse_tab(t_data *data)
{
  int	i;
  int	j;

  i = 1;
  while (data->opt.arg[i + 1])
    {
      j = 3;
      while (data->opt.to_check[j])
	if ((check_all_option(data, &i, &j)) == 2)
	  break ;
      i++;
    }
  if (j == 20)
    return (my_putstr("Wrong arguments\n"), 1);
  return (0);
}
