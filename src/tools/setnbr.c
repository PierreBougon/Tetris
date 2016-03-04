/*
** setnbr.c for SETNBR in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Jan 22 05:11:57 2016 bougon_p
** Last update Fri Mar  4 23:51:18 2016 bougon_p
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
  if (p == 10)
    {
      clean[0] = '0';
      clean[1] = 0;
      free(nbr);
      return (clean);
    }
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

char	*reset(char *str, char *nbr)
{
  free(nbr);
  str[1] = str[0];
  str[0] = '0';
  str[3] = 0;
  return (str);
}

char	*timecleanstr(char *nbr)
{
  char	*clean;
  int	p;
  int	i;

  if ((clean = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  clean = set_line_null(clean, 10);
  p = 0;
  while (nbr[p++] == '0' && p < 10);
  if (p == 10)
    {
      clean[0] = '0';
      clean[1] = '0';
      clean[2] = 0;
      free(nbr);
      return (clean);
    }
  i = 0;
  p--;
  while (nbr[p] != 0)
    clean[i++] = nbr[p++];
  if (my_strlen(clean) == 1)
    return (reset(clean, nbr));
  free(nbr);
  return (clean);
}

char	*timesetnbr(int nbr)
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
  return (timecleanstr(numb));
}
