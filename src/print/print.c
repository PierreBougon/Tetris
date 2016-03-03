/*
** print.c for PRINT in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 22:45:02 2016 bougon_p
** Last update Wed Mar  2 17:45:49 2016 Clémenceau Cedric
*/

#include "tetris.h"

char	*check_highscore(char *nb)
{
  char	*tmp;
  int	i;
  int	count;

  count = 0;
  if ((tmp = malloc(6)) == NULL)
    return (NULL);
  i = my_strlen(nb) - 1;
  while (count < (5 - i - 1))
    tmp[count++] = ' ';
  i = 0;
  while (nb[i])
    tmp[count++] = nb[i++];
  tmp[count] = 0;
  free(nb);
  return (tmp);
}

void	print_score(t_score *score)
{
  int	i;
  char	*nb;
  char	*time_min;
  char	*time_sec;

  i = -1;
  nb = setnbr(score->high_score);
  time_min = timesetnbr(score->act_time / 60);
  time_sec = timesetnbr(score->act_time % 60);
  nb = check_highscore(nb);
  my_strncpy(&score->tab_score[2][13], nb, my_strlen(nb));
  my_strncpy(&score->tab_score[3][17], "0", my_strlen("0"));
  my_strncpy(&score->tab_score[5][17], "0", my_strlen("0"));
  my_strncpy(&score->tab_score[6][17], "1", my_strlen("1"));
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
  data->score.act_time = time(NULL) - data->score.init_time;
  write_tetris();
  print_score(&data->score);
  print_game(data);
  mvprintw(22, 0, "EpiTetris(c) - 2015");
}
