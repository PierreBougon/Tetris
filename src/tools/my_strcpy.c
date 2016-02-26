/*
** my_strcpy.c for all in /home/clemen_j/tek1/ElemProg_C/BSQ/CPE_2015_BSQ/src
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Dec  7 21:41:47 2015 Cédric Clemenceau
** Last update Thu Feb 25 01:07:27 2016 Clémenceau Cedric
*/

#include "tetris.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
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
  while (i < octet)
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
