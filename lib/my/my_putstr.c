/*
** my_putstr.c for PUTSTR in /home/bougon_p/rendu/CPE_2015_Allum1/lib/my
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 18 16:44:34 2016 bougon_p
** Last update Sat Mar 12 15:10:09 2016 Clémenceau Cedric
*/

#include "my.h"
#include <unistd.h>

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
