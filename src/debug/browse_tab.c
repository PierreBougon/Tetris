/*
** browse_tab.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sat Mar  5 22:07:39 2016 Clémenceau Cedric
** Last update Sat Mar 19 16:48:04 2016 Clémenceau Cedric
*/

#include "tetris.h"

char	*check_echap(char *to_check)
{
  int	i;
  int	j;
  char	*to_send;

  i = -1;
  j = 0;
  if ((to_send = malloc(sizeof(char) * (my_strlen(to_check) + 1))) == NULL)
    return (NULL);
  while (to_check[++i])
    if ((to_check[i] == '\\' && to_check[i + 1] == 'e') ||
	(to_check[i] == '\\' && to_check[i + 1] == 'E') ||
	(to_check[i] == '^' && to_check[i + 1] == 'E')  ||
	(to_check[i] == '^' && to_check[i + 1] == 'e'))
      {
	to_send[j++] = 27;
	i = i + 2;
	while (to_check[i])
	  to_send[j++] = to_check[i++];
      }
  to_send[j] = 0;
  return ((to_send[0] == 0) ? free(to_send), to_check : to_send);
}

void	aff_tetrimi(t_cdlist *list, int *i)
{
  my_putstr(list->data->item[(*i)++]);
  write(1, "\n", 1);
}

int	check_tetrimino(t_cdlist *list)
{
  my_putstr("Tetriminos : Name ");
  my_putstr(list->data->name);
  my_putstr(" : Size ");
  my_put_nbr(list->data->width);
  write(1, "*", 1);
  my_put_nbr(list->data->height);
  my_putstr(" : Color ");
  my_put_nbr(list->data->color);
  write(1, " :\n", 3);
  return (0);
}

int	check_all_option(t_data *data, int *i, int *j)
{
  if ((my_strcmp(data->opt.arg[(*i)], data->opt.to_check[1])) == 0 ||
      (my_strcmp(data->opt.arg[(*i)], data->opt.to_check[2])) == 0)
    return (2);
  if ((my_strcmp(data->opt.arg[(*i)], data->opt.to_check[(*j)])) == 0)
    {
      if ((data->tetris_tab[(*j)](data, data->opt.key_to_set[*i])) == 1)
	return (1);
      if ((*j) == 7 || (*j) == 8 || (*j) == 10 || (*j) == 12 || (*j) == 14 ||
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
    return (my_putstr("Wrong argumennts\n"), 1);
  return (0);
}
