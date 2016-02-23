/*
** print.c for PRINT in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 22:45:02 2016 bougon_p
** Last update Wed Feb 24 00:47:40 2016 bougon_p
*/

#include "tetris.h"

void	write_tetris()
{
  init_pair(1, 2, 0);
  attron(COLOR_PAIR(1));
  printw("                                              PLEURE PAS <3\n");
  printw("*** *** *** *** * ***\n");
  printw(" *  *    *  * *   *  \n");
  printw(" *  ***  *   ** * ***\n");
  printw(" *  *    *  * * *   *\n");
  printw(" *  ***  *  * * * ***\n");
  printw("\n\n\n");
  attroff(COLOR_PAIR(1));
}

void	print_ligne(t_score *score, char *to_print, int pos_x, int pos_y)
{
  score = score;
  mvprintw(pos_x, pos_y, to_print);
}

void	print_score(t_score *score)
{
  print_ligne(score, " /------------------\\\n", 10, 0);
  printw(" |                  |\n");
  printw(" | High Score   %d  |\n", score->high_score);
  printw(" | Score            |\n");
  printw(" |                  |\n");
  printw(" | Lines            |\n");
  printw(" | Level            |\n");
  printw(" |                  |\n");
  printw(" | Timer:           |\n");
  printw(" \\------------------/\n");
}

void	aff_layout(t_score *score)
{
  write_tetris();
  print_score(score);
}
