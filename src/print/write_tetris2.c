/*
** write_tetris2.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Thu Feb 25 02:20:43 2016 Clémenceau Cedric
** Last update Thu Feb 25 02:25:26 2016 Clémenceau Cedric
*/

#include "tetris.h"

void	write_letter_s()
{
  mvprintw(1, 19, "***");
  mvprintw(2, 19, "*  ");
  mvprintw(3, 19, "***");
  mvprintw(4, 19, "  *");
  mvprintw(5, 19, "***");
}

void	write_tetris()
{
  init_color(COLOR_BLUE, 1000, 500, 700);
  init_pair(1, 1, COLOR_BLACK);
  init_pair(2, 5, COLOR_BLACK);
  init_pair(3, 3, COLOR_BLACK);
  init_pair(4, 2, COLOR_BLACK);
  init_pair(5, 6, COLOR_BLACK);
  init_pair(6, COLOR_BLUE, COLOR_BLACK);
  attrset(COLOR_PAIR(1));
  write_letter();
  attroff(COLOR_PAIR(1));
  attrset(COLOR_PAIR(2));
  write_letter_e();
  attroff(COLOR_PAIR(2));
  attrset(COLOR_PAIR(3));
  write_letter_t();
  attroff(COLOR_PAIR(3));
  attrset(COLOR_PAIR(4));
  write_letter_r();
  attroff(COLOR_PAIR(4));
  attrset(COLOR_PAIR(5));
  write_letter_i();
  attroff(COLOR_PAIR(5));
  attrset(COLOR_PAIR(6));
  write_letter_s();
  attroff(COLOR_PAIR(6));
}
