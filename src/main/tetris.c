/*
** tetris.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:12:05 2016 bougon_p
** Last update Thu Feb 25 14:25:00 2016 Clémenceau Cedric
*/

#include "tetris.h"

t_options	parse_params(int ac, char **av)
{
  t_options	option;

  ac = ac;
  av = av;
  option = option;
  return (option);
}

int	main_loop(t_data *data, t_options *opt)
{
  int	key;

  data = data;
  opt = opt;
  while (1)
    {
      clear();
      initscr();
      aff_layout(data);
      key = getch();
      if (key == KEY_ESC)
      	break ;
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  t_data	data;
  t_options	opt;

  data.score.high_score = 0;
  ac = ac;
  av = av;
  data = data;
  opt = opt;

  initscr();
  if (has_colors() == FALSE)
    {
      endwin();
      return (my_putstr_err("Your terminal does not support color\n"));
    }
  if (*env == NULL)
    return (my_putstr_err("No environment detected\n"));
  opt = parse_params(ac, av);

  data.score.tab_score = init_tab(10, 20);
  data.tab_game = init_tab(20, 10);
  data.tab_next = init_tab(4, 8);

  /* if ((data.tetriminos = init_tetriminos()) == NULL) */
  /*   return (my_putstr_err("Corrupted file\n")); */
  /* if ((data.score.tab_score = init_tab(10, 20)) == NULL) */
  /*   return (my_putstr_err("Malloc error\n")); */


  start_color();
  my_init_color();
  curs_set(0);
  main_loop(&data, &opt);
  endwin();
  return (0);
}
