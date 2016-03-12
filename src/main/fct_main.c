/*
** fct_main.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Feb 29 20:02:47 2016 Clémenceau Cedric
** Last update Sat Mar 12 21:37:35 2016 bougon_p
*/

#include "tetris.h"

int	init_data(t_data *data, char **av, int ac)
{
  if ((init_tetriminos(&data->tetriminos)) == 1)
    return (my_putstr_err("Corrupted file\n"), 1);
  check_max(data);
  init_base(data);
  if (ac > 1)
    if ((my_check_option(data, av)) == 1)
      return (1);
  if ((data->tab_game = init_tab_game(data->gamevar.win_height,
				      data->gamevar.win_width)) == NULL)
    return (1);
  if ((data->score.tab_score = init_tab(10, 20)) == NULL)
    return (1);
  init_tabscore(data->score.tab_score);
  if ((data->win = initscr()) == NULL)
    return (1);
  clear();
  if (data->gamevar.win_width + POS_GAME_X + 25 > getmaxx(data->win))
    return (my_putstr("Window too short\n"), 1);
  if (data->gamevar.win_height + 10 > getmaxy(data->win))
    return (my_putstr("Window too short\n"), 1);
  if ((do_sub(data)) == 1)
    return (1);
  data->gamevar.speed -= data->gamevar.level / 12.0;
  return (0);
}

int	help(t_data *data, char *str)
{
  my_putstr("Usage: ");
  my_putstr(str);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("  --help                 Display this help\n");
  my_putstr("  -l --level={num}       Start Tetris at level num\n");
  my_putstr_keys(data);
  my_putstr("  --map-size={row,col}   Set game size at row, col\n");
  my_putstr("  -w --without-next      Hide next tetrimino\n");
  my_putstr("  -d --debug             Debug mode\n");
  return (1);
}

int	my_check_option(t_data *data, char **option)
{
  if ((data->tetris_tab = malloc(sizeof(data->tetris_tab) * 20)) == NULL)
    return (1);
  if ((parsing_arg(option, data)) == 1)
    return (1);
  fill_tab(data);
  if ((check_arg(option, data, 0)) == 1)
    return (1);
  if ((browse_tab(data)) == 1)
    return (1);
  if ((check_arg(option, data, 1)) == 1)
    return (1);
  fonction(data);
  return (0);
}

void	aff_size(t_data *data)
{
  my_putstr("Size : ");
  my_put_nbr(data->gamevar.win_height);
  write(1, "*", 1);
  my_put_nbr(data->gamevar.win_width);
  write(1, "\n", 1);
}

int	debug_mode(t_data *data, char *str)
{
  str = str;
  my_putstr("*** DEBUG MODE ***\n");
  aff_keys(data);
  aff_next(data);
  write(1, "Level : ", 8);
  my_put_nbr(data->gamevar.level);
  write(1, "\n", 1);
  aff_size(data);
  aff_tetriminos(data);
  my_putstr("Press a key to start Tetris\n");
  if ((my_infinite_loop()) == 1)
    return (1);
  return (0);
}
