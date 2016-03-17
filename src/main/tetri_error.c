/*
** tetri_error.c for ERROR in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Mar  6 16:24:23 2016 bougon_p
** Last update Thu Mar 17 17:16:56 2016 bougon_p
*/

#include "tetris.h"

void	exit_no_tetri()
{
  my_putstr_err("There is no tetrimino on tetriminos/ file !\n");
  exit(1);
}

void	epurendstr(char *str)
{
  int	i;

  i = my_strlen(str);
  while (str[--i] == ' ')
    {
      str[i] = 0;
    }
}

int	check_save(char *str, t_tetri *tetri)
{
  int	i;

  i = -1;
  if (str[0] == 0)
    return (1);
  while (str[++i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
	tetri->error = true;
    }
  return (0);
}

char	*get_extens(char *name)
{
  int	i;
  char	*extens;

  i = my_strlen(name);
  while (i > 0 && name[--i] != '.');
  extens = &name[i];
  return (extens);
}

int	check_name(char *name)
{
  char	*extens;

  extens = get_extens(name);
  if (my_strcmp(extens, ".tetrimino") != 0)
    {
      return (1);
    }
  return (0);
}
