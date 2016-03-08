/*
** my_strcpy.c for all in /home/clemen_j/tek1/ElemProg_C/BSQ/CPE_2015_BSQ/src
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Dec  7 21:41:47 2015 Cédric Clemenceau
** Last update Tue Mar  8 02:17:30 2016 Clémenceau Cedric
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

int	my_putstr_debug(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 27)
	write(1, "^E", 2);
      else if (str[i] == ' ')
	write(1, "(space)", 7);
      else
	write(1, &str[i], 1);
      i++;
    }
  return (0);
}
