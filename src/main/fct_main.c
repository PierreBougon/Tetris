/*
** fct_main.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Feb 29 20:02:47 2016 Clémenceau Cedric
** Last update Sat Mar  5 17:07:25 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	init_data(t_data *data, char **av, int ac)
{
  if ((init_tetriminos(&data->tetriminos)) == 1)
    return (my_putstr_err("Corrupted file\n"), 1);
  check_max(data);
  data->gamevar.win_width = 10;
  data->gamevar.win_height = 20;
  if (ac > 1)
    if ((my_check_option(data, av)) == 1)
      return (1);
  init_base(data);
  data->score.tab_score = init_tab(10, 20);
  init_tabscore(data->score.tab_score);
  data->win = initscr();
  clear();
  data->sub_win = subwin(data->win, 20, 12, 1, POS_GAME_X);
  if (data->boole == 0)
    data->sub_next = subwin(data->win, (data->gamevar.maxheight >= 4) ?
			    data->gamevar.maxheight + 2 : 5,
			    (data->gamevar.maxwidth >= 7) ?
			    data->gamevar.maxwidth + 2 : 8,
			    1, POS_GAME_X + 15);
  return (0);
}

int	help(t_data *data, char *str)
{
  str = str;
  my_putstr("Usage: ./tetris [options]\n");
  my_putstr("Options:\n");
  my_putstr("--help\t\t\tDisplay this help\n");
  my_putstr("-l --level={num}\tStart Tetris at level num\n");
  my_putstr_keys(data);
  my_putstr("-w --without-next\tHide next tetriminos\n");
  my_putstr("-d --debug\t\tDebug mode\n");
  return (1);
}

int	my_check_option(t_data *data, char **option)
{
  int	i;
  int	j;
  int	(*tetris_tab[6])(t_data *, char *);

  i = 1;
  j = 0;
  /* if ((check_arg()) == 1) */
  /*   return (1); */
  if ((parsing_arg(option, data)) == 1)
    return (1);
  tetris_tab[0] = help;
  tetris_tab[1] = debug_mode;
  tetris_tab[2] = debug_mode;
  tetris_tab[3] = map_size;
  tetris_tab[4] = without_next;
  tetris_tab[5] = without_next;
  /* tetris_tab[1] = level; */
  /* tetris_tab[2] = key_left; */
  /* tetris_tab[3] = key_right; */
  /* tetris_tab[4] = key_turn; */
  /* tetris_tab[5] = key_drop; */
  /* tetris_tab[6] = key_quit; */
  /* tetris_tab[7] = key_pause; */
  while (data->opt.arg[i])
    {
      j = 0;
      while (data->opt.to_check[j])
  	if (my_strcmp(data->opt.arg[i], data->opt.to_check[j]) == 0)
  	  {
  	    if ((tetris_tab[j](data, data->opt.entered_key)) == 1)
	      return (1);
  	    j++;
  	  }
  	else
  	  j++;
      /* if (j > 5) */
      /* 	return (my_putstr("No arguments valaible\n"), 1); */
      i++;
    }
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
  my_infinite_loop();
  return (0);
}
