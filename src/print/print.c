/*
** print.c for PRINT in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 22:45:02 2016 bougon_p
** Last update Sat Feb 27 23:22:33 2016 bougon_p
*/

#include "tetris.h"

void	print_ligne(t_score *score, char *to_print, int pos_x, int pos_y)
{
  char	*nb;
  char	time_now[6];

  my_strcpy(score->tab_score[pos_x - 10], to_print);
  /* setnbr(data->highscore) */
  nb = setnbr(score->high_score);
  my_strcpy(time_now, "0:0");
  my_strncpy(&score->tab_score[2][13], nb, my_strlen(nb));
  my_strncpy(&score->tab_score[3][17], "0", my_strlen("0"));
  my_strncpy(&score->tab_score[5][17], "0", my_strlen("0"));
  my_strncpy(&score->tab_score[6][17], "1", my_strlen("1"));
  my_strncpy(&score->tab_score[8][15], time_now, my_strlen(time_now));
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
  my_strcpy(data->tab_game[pos_x - 1], to_print);
  mvprintw(pos_x, pos_y, data->tab_game[pos_x - 1]);
}

void	print_game(t_data *data)
{
  int	i;

  i = 2;
  print_ligne_map(data, "------------", 1, POS_GAME_X);
  while (i < 22)
    print_ligne_map(data, "|          |", i++, POS_GAME_X);
  print_ligne_map(data, "------------", 22, POS_GAME_X);
}

void	print_ligne_next(t_data *data, char *to_print, int pos_x, int pos_y)
{
  my_strcpy(data->tab_next[pos_x - 1], to_print);
  mvprintw(pos_x, pos_y, data->tab_next[pos_x - 1]);
}

void	print_next(t_data *data)
{
  print_ligne_next(data, "/Next--\\", 1, POS_GAME_X + 15);
  print_ligne_next(data, "|      |", 2, POS_GAME_X + 15);
  print_ligne_next(data, "|      |", 3, POS_GAME_X + 15);
  print_ligne_next(data, "\\------/", 4, POS_GAME_X + 15);
}

void	aff_layout(t_data *data)
{
  write_tetris();
  print_score(&data->score);
  print_game(data);
  print_next(data);
  mvprintw(22, 0, "EpiTetris(c) - 2015");
}
