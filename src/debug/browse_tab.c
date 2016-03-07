/*
** browse_tab.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sat Mar  5 22:07:39 2016 Clémenceau Cedric
** Last update Mon Mar  7 00:58:25 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	browse_tab(t_data *data)
{
  int	i;
  int	j;

  i = 1;
  while (data->opt.arg[i + 1])
    {
      j = 3;
      while (data->opt.to_check[j])
	{
	  if ((my_strcmp(data->opt.arg[i], "-d")) == 0 ||
	      (my_strcmp(data->opt.arg[i], "--debug")) == 0)
	    break ;
	  if ((my_strcmp(data->opt.arg[i], data->opt.to_check[j])) == 0)
	    {
	      if ((data->tetris_tab[j](data, data->opt.entered_key)) == 1)
		return (1);
	      break ;
	    }
	  j++;
	}
      i++;
    }
  if (j == 20)
    return (my_putstr("Wrong arguments\n"), 1);
  return (0);
}
