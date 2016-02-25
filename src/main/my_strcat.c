/*
** my_strcat.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 25 17:10:44 2016 bougon_p
** Last update Thu Feb 25 17:12:29 2016 bougon_p
*/

#include "tetris.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = my_strlen(dest);
  j = 0;
  while (src[j])
      dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}
