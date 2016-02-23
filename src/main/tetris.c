/*
** tetris.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:12:05 2016 bougon_p
** Last update Tue Feb 23 19:22:20 2016 bougon_p
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
      mvprintw(10, 10, "coucoucmqskjhfuegfyuegdij");
      key = getch();
      if (key == KEY_ESC)
      	break;
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_data	data;
  t_options	opt;


  data = data;
  opt = opt;
  ac = ac;
  av = av;
  if (*env == NULL)
    return (my_putstr_err("No environment detected\n"));
  keypad(stdscr, TRUE);
  initscr();
  curs_set(0);
  opt = parse_params(ac, av);
  main_loop(&data, &opt);
  endwin();
  return (0);
}
