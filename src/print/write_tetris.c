/*
** write_tetris.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Thu Feb 25 02:20:12 2016 Clémenceau Cedric
** Last update Thu Feb 25 02:24:52 2016 Clémenceau Cedric
*/

#include "tetris.h"

void	write_letter()
{
  mvprintw(1, 1, "***");
  mvprintw(2, 1, " * ");
  mvprintw(3, 1, " * ");
  mvprintw(4, 1, " * ");
  mvprintw(5, 1, " * ");
}

void	write_letter_e()
{
  mvprintw(1, 5, "***");
  mvprintw(2, 5, "*  ");
  mvprintw(3, 5, "** ");
  mvprintw(4, 5, "*  ");
  mvprintw(5, 5, "***");
}

void	write_letter_t()
{
  mvprintw(1, 9, "***");
  mvprintw(2, 9, " * ");
  mvprintw(3, 9, " * ");
  mvprintw(4, 9, " * ");
  mvprintw(5, 9, " * ");
}

void	write_letter_r()
{
  mvprintw(1, 13, "***");
  mvprintw(2, 13, "* *");
  mvprintw(3, 13, " **");
  mvprintw(4, 13, "* *");
  mvprintw(5, 13, "* *");
}

void	write_letter_i()
{
  mvprintw(1, 16, " * ");
  mvprintw(2, 16, "   ");
  mvprintw(3, 16, " * ");
  mvprintw(4, 16, " * ");
  mvprintw(5, 16, " * ");
}
