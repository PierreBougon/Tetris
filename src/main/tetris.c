/*
** tetris.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:12:05 2016 bougon_p
** Last update Tue Feb 23 22:03:36 2016 Clémenceau Cedric
*/

#include "tetris.h"


void	write_tetris()
{
  printw("						PLEURE PAS <3\n");
  printw("*** *** *** *** * ***\n");
  printw(" *  *    *  * *   *  \n");
  printw(" *  ***  *   ** * ***\n");
  printw(" *  *    *  * * *   *\n");
  printw(" *  ***  *  * * * ***\n");
  printw("\n\n\n");
}

void	print_score()
{
  printw(" /------------------\\\n");
  printw(" |                  |\n");
  printw(" | High Score       |\n");
  printw(" | Score            |\n");
  printw(" |                  |\n");
  printw(" | Lines            |\n");
  printw(" | Level            |\n");
  printw(" |                  |\n");
  printw(" | Timer            |\n");
  printw(" \\------------------/\n");
}

void	aff_layout()
{
  write_tetris();
  print_score();
}

int	main(int ac, char **av, char **env)
{
  av = av;
  if (env[0] == NULL || ac < 1)
    {
      write(2, "Error\n", 6);
      return (-1);
    }
  initscr();
  aff_layout();
  refresh();
  getch();
  endwin();
  return (0);
}
