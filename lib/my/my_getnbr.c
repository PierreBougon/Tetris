/*
** my_getnbr.c for minitalk in /home/clemen_j/Work/PSU/PSU_2015_minitalk
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Feb  1 22:57:04 2016 Clémenceau Cedric
** Last update Sat Mar 12 15:09:06 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	my_getnbr(char *str)
{
  int	nb;
  int	i;
  int	boole;

  nb = 0;
  i = 0;
  boole = 0;
  if (str == NULL)
    return (free(str), -1);
  if (str[i] == '-')
    {
      nb = -nb;
      i++;
      boole = 1;
    }
  if (str[i] < '0' || str[i] > '9')
    return (-1);
  while (str[i])
    {
      nb = 10 * nb + (str[i] - 48);
      i++;
    }
  return (boole == -nb ? -1 : nb);
}
