/*
** error.c for ERROR in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 18:56:41 2016 bougon_p
** Last update Thu Feb 25 16:49:34 2016 bougon_p
*/

#include "tetris.h"

int	my_putstr_err(char *str)
{
  endwin();
  write(2, str, my_strlen(str));
  return(1);
}
