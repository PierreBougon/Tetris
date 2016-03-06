/*
** error.c for ERROR in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 18:56:41 2016 bougon_p
** Last update Sun Mar  6 18:27:37 2016 bougon_p
*/

#include "tetris.h"

int	my_putstr_err(char *str)
{
  endwin();
  write(2, str, my_strlen(str));
  return (1);
}

int	launch_main(t_data *data, int game)
{
  int	j;
  int	i;

  j = -1;
  while (++j < data->gamevar.win_height)
    set_null(data->tab_game[j], data->gamevar.win_width + 1);
  if (game != 0)
    {
      free_list(&data->tetri_ig);
      clear();
      mvprintw(getmaxy(data->win) / 2,
	       ((getmaxx(data->win) / 2) - 11),
	       "You lose ! Try again !!");
      mvprintw(getmaxy(data->win) / 2 + 1,
	       ((getmaxx(data->win) / 2) - 16),
	       "Press any key to restart the game");
      refresh();
      my_infinite_loop();
      clear();
      i = -1;
      while (++i < 4)
	my_strncpy(&data->score.tab_score[3][13 + i], " ", 1);
      data->score.score = 0;
    }
  return (main_loop(data));
}

int	config(t_data *data)
{
  int	ret;
  int	game;

  noecho();
  keypad(stdscr, true);
  data->keys = init_keys();
  init_keytab(&data->tabkey);
  nodelay(data->win, true);
  if (has_colors() == false)
    {
      endwin();
      return (my_putstr_err("Your terminal does not support color\n"), 1);
    }
  srand(time(0));
  start_color();
  my_init_color();
  curs_set(0);
  game = 0;
  while ((ret = launch_main(data, game++)) == -3);
  if (ret == 1)
    return (1);
  return (0);
}
