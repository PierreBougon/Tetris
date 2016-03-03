/*
** fct_main.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Feb 29 20:02:47 2016 Clémenceau Cedric
** Last update Thu Mar  3 10:53:50 2016 bougon_p
*/

#include "tetris.h"

void	init_data(t_data *data)
{
  data->score.high_score = 0;
  data->gamevar.speed = 1;
  data->gamevar.win_width = 10;
  data->gamevar.win_height = 20;
  data->tab_game = init_tab_game(data->gamevar.win_height,
		data->gamevar.win_width);
  data->score.tab_score = init_tab(10, 20);
  init_tabscore(data->score.tab_score);
  data->win = initscr();
  clear();
  data->sub_win = subwin(data->win, 20, 12, 1, POS_GAME_X);
  dprintf(2, "maxwidth = %d", data->gamevar.maxwidth);
  data->sub_next = subwin(data->win,
			 (data->gamevar.maxheight > 7) ?
			 data->gamevar.maxheight + 2 : 9,
			 (data->gamevar.maxwidth > 10) ?
			 data->gamevar.maxwidth + 1 : 11,
			 1, POS_GAME_X + 15);
}

void	my_check_option(t_data *data, char **option)
{
  return ;
}
