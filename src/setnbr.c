/*
** setnbr.c for SETNBR in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Jan 22 05:11:57 2016 bougon_p
** Last update Fri Feb 26 12:25:11 2016 bougon_p
*/

#include "tetris.h"

char	*cleanstr(char *nbr)
{
  char	*clean;
  int	p;
  int	i;

  if ((clean = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  clean = set_line_null(clean, 10);
  p = 0;
  while (nbr[p++] == '0' && p < 10);
  i = 0;
  p--;
  while (nbr[p] != 0)
    clean[i++] = nbr[p++];
  free(nbr);
  return (clean);
}

char	*setnbr(int nbr)
{
  char	*numb;
  int	i;
  int	p;

  p = 8;
  if ((numb = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  set_line_null(numb, 10);
  i = 0;
  while (p >= 0)
    numb[p--] = ((nbr / (int)(my_pow(10, i++)) % 10) + '0');
  return (cleanstr(numb));
}
