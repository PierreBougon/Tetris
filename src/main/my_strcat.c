/*
** my_strcat.c for my_ls in /home/clemen_j/tek1/System_Unix/MyLs/PSU_2015_my_ls/src
**
** Made by Cédric Clemenceau
** Login   <clemen_j@epitech.net>
**
** Started on  Sun Nov 29 20:40:28 2015 Cédric Clemenceau
** Last update Wed Feb 24 17:37:39 2016 Clémenceau Cedric
*/

#include "tetris.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = my_strlen(dest);
  i = 0;
  while (src[i])
      dest[j++] = src[i++];
  dest[i] = '\0';
  return (dest);
}
