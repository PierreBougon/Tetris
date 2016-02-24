/*
** print.c for PRINT in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 22:45:02 2016 bougon_p
** Last update Wed Feb 24 19:44:43 2016 Clémenceau Cedric
*/

#include "tetris.h"

void	write_tetris()
{
  init_pair(1, 2, 0);
  attrset(COLOR_PAIR(1));
  printw("                                              PLEURE PAS <3\n");
  printw("*** *** *** *** * ***\n");
  printw(" *  *    *  * *   *  \n");
  printw(" *  ***  *   ** * ***\n");
  printw(" *  *    *  * * *   *\n");
  printw(" *  ***  *  * * * ***\n");
  attroff(COLOR_PAIR(1));
}

void	print_ligne(t_score *score, char *to_print, int pos_x, int pos_y)
{
  char	*int;
  strcpy(score->tab_score[pos_x - 10], to_print);

  mvprintw(pos_x, pos_y, score->tab_score[pos_x - 10]);
}

void	print_score(t_score *score)
{
  print_ligne(score, "/------------------\\", 10, 0);
  print_ligne(score, "|                  |", 11, 0);
  print_ligne(score, "| High Score       |", 12, 0);
  print_ligne(score, "| Score            |", 13, 0);
  print_ligne(score, "|                  |", 14, 0);
  print_ligne(score, "| Lines            |", 15, 0);
  print_ligne(score, "| Level            |", 16, 0);
  print_ligne(score, "|                  |", 17, 0);
  print_ligne(score, "| Timer:           |", 18, 0);
  print_ligne(score, "\\------------------/", 19, 0);
}

void	print_ligne_map(t_data *data, char *to_print, int pos_x, int pos_y)
{
  data->tab_game[pos_x] = to_print;
  mvprintw(pos_x, pos_y, data->tab_game[pos_x]);
}

void	print_game(t_data *data)
{
  int	i;

  i = 2;
  print_ligne_map(data, "--------------------", 1, POS_GAME);
  while (i < 20)
    print_ligne_map(data, "|                  |", i++, POS_GAME);
  print_ligne_map(data, "--------------------", 20, POS_GAME);

}

void	print_next(t_data *data)
{
  print_ligne_map(data, "/Next--\\", 1, POS_GAME + 25);
  print_ligne_map(data, "|      |", 2, POS_GAME + 25);
  print_ligne_map(data, "|      |", 3, POS_GAME + 25);
  print_ligne_map(data, "\\------/", 4, POS_GAME + 25);
}

void	aff_layout(t_data *data)
{
  write_tetris();
  print_score(&data->score);
  print_game(data);
  print_next(data);
}
