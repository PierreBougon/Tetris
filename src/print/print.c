/*
** print.c for PRINT in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 22:45:02 2016 bougon_p
** Last update Fri Mar 18 14:30:19 2016 bougon_p
*/

#include "tetris.h"

void	set_score_in_tab(t_score *score, int level)
{
  char	*mscore;
  char	*line;
  char	*lvl;

  mscore = setnbr(score->score);
  my_strncpy(&score->tab_score[3][17 - (my_strlen(mscore) - 1)],
	     mscore, my_strlen(mscore));
  line = setnbr(score->line);
  my_strncpy(&score->tab_score[5][17 - (my_strlen(line) - 1)],
	     line, my_strlen(line));
  lvl = setnbr(level);
  my_strncpy(&score->tab_score[6][17 - (my_strlen(lvl) - 1)],
	     lvl, my_strlen(lvl));
  free(mscore);
  free(line);
  free(lvl);
}

void	print_score(t_score *score, int level)
{
  int	i;
  char	*nb;
  char	*time_min;
  char	*time_sec;

  i = -1;
  set_score_in_tab(score, level);
  time_min = timesetnbr(score->act_time / 60);
  time_sec = timesetnbr(score->act_time % 60);
  score->high_score = (score->score > score->high_score)
    ? score->score : score->high_score;
  nb = setnbr(score->high_score);
  my_strncpy(&score->tab_score[2][17 - (my_strlen(nb) - 1)], nb, my_strlen(nb));
  my_strncpy(&score->tab_score[8][11], time_min, my_strlen(time_min));
  my_strncpy(&score->tab_score[8][11 + my_strlen(time_min) + 1], ":", 1);
  my_strncpy(&score->tab_score[8][11 + my_strlen(time_min) + 3]
  	     , time_sec, my_strlen(time_sec));
  while (score->tab_score[++i])
    mvprintw((i + 10), 0, score->tab_score[i]);
  free(nb);
  free(time_min);
  free(time_sec);
}

void	print_game(t_data *data)
{
  werase(data->sub_win);
  wborder(data->sub_win, '|', '|', '-', '-', '/', '\\', '\\', '/');
}

void	aff_layout(t_data *data)
{
  data->score.act_time =
    time(NULL) - data->score.init_time - data->score.tpause;
  write_tetris();
  print_score(&data->score, data->gamevar.level);
  print_game(data);
  mvprintw(22, 0, "EpiTetris(c) - 2015");
}
