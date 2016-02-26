/*
** tetris.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:12:05 2016 bougon_p
** Last update Fri Feb 26 19:04:36 2016 bougon_p
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
  int	refind;

  opt = opt;
  refind = -1;
  while (1)
    {
      clear();
      initscr();
      if ((refind = find_new_tetri(data, refind)) == -2)
	return (1);
      aff_layout(data);
      aff_piece(&data->tetri_ig);
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
  opt = opt;

  if ((init_tetriminos(&data.tetriminos)) == 1)
    return (my_putstr_err("Corrupted file\n"));

  /*
  **  DEBUG MODE
  */
  /* print_tetri(&data.tetriminos); */
  /* exit(1); */

  initscr();
  if (has_colors() == FALSE)
    {
      endwin();
      return (my_putstr_err("Your terminal does not support color\n"));
    }
  if (*env == NULL)
    return (my_putstr_err("No environment detected\n"));
  opt = parse_params(ac, av);

  srand(time(0));
  data.score.tab_score = init_tab(10, 20);
  data.tab_game = init_tab(20, 10);
  data.tab_next = init_tab(4, 8);

  /* if ((data.score.tab_score = init_tab(10, 20)) == NULL) */
  /*   return (my_putstr_err("Malloc error\n")); */


  start_color();
  curs_set(0);
  main_loop(&data, &opt);
  endwin();
  free_list(&data.tetriminos);
  return (0);
}
