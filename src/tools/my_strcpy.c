/*
** my_strcpy.c for all in /home/clemen_j/tek1/ElemProg_C/BSQ/CPE_2015_BSQ/src
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Dec  7 21:41:47 2015 Cédric Clemenceau
** Last update Fri Mar  4 18:15:14 2016 Clémenceau Cedric
*/

#include "tetris.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (!src)
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strncpy(char *dest, char *src, int octet)
{
  int	i;

  i = 0;
  if (!src)
    return (NULL);
  while (i < octet)
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}

char	*my_strdup(char *s)
{
  int	size;
  char	*str;

  size = my_strlen(s) + 1;
  if ((str = malloc(size)) == NULL)
    return (NULL);
  return (str);
}
