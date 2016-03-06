/*
** browse_tab.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sat Mar  5 22:07:39 2016 Clémenceau Cedric
** Last update Sun Mar  6 16:45:12 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	browse_tab(t_data *data)
{
  int	i;
  int	j;

  i = 0;
  j = 3;
  while (data->opt.arg[i])
    {
      while (data->opt.to_check[j])
	{
	  if (my_strcmp(data->opt.arg[i], data->opt.to_check[j]) == 0)
	    {
	      /* if ((my_strcmp(data->opt.arg[i], "-d")) == 0 || */
	      /* 	 (my_strcmp(data->opt.arg[i], "--debug")) == 0) */
	      /* 	j++; */
	      /* else */
		if ((data->tetris_tab[j](data, data->opt.entered_key)) == 1)
		  return (1);
	      j++;
	    }
	  else
	    j++;
	}
      j = 3;
      i++;
    }
  return (0);
}
