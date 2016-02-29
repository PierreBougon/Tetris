
/*
** tetris.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:12:05 2016 bougon_p
** Last update Mon Feb 29 20:05:59 2016 bougon_p
*/

#include "tetris.h"

/* t_options	parse_params(int ac, char **av) */
/* { */
/*   t_options	option; */

/*   ac = ac; */
/*   av = av; */
/*   option = option; */
/*   return (option); */
/* } */

int             get_key(t_data *data, int key, int *keys, t_tabkey *tab)
{
  int           i;

  i = 0;
  while (key != keys[i])
    {
      i++;
      if (i > 5)
        return (0);
    }
  return (tab->tabkey[i](data, &data->tetri_ig));
}

int	main_loop(t_data *data, t_options *opt)
{
  int	key;
  int	refind;
  float	to_move;

  opt = opt;
  refind = -1;
  to_move = 0;
  while (1)
    {
      refresh();
      wrefresh(data->sub_next);
      if ((refind = find_new_tetri(data, refind)) == -2)
	return (1);
      aff_layout(data);
      init_tabnext(data, data->tetri_ig._root->next->data->item);
      aff_piece(data->sub_win, &data->tetri_ig);
      to_move = need_to_move(data, to_move);
      refind = need_to_stop(data, refind);
      key = getch();
      if (get_key(data, key, data->keys, &data->tabkey) == 1)
	break;
      usleep(1);
    }
  return (0);
}

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

int	main(int ac, char **av, char **env)
{
  t_data	data;
  t_options	opt;


  data.score.init_time = time(NULL);
  data.score.high_score = 0;
  ac = ac;
  av = av;
  opt = opt;

  if ((init_tetriminos(&data.tetriminos)) == 1)
    return (my_putstr_err("Corrupted file\n"));
  check_max(&data);

  /*
  **  DEBUG MODE
  */
  /* print_tetri(&data.tetriminos); */
  /* exit(1); */


  data.gamevar.speed = 1;
  data.gamevar.win_width = 10;
  data.gamevar.win_height = 20;
  data.win = initscr();
  clear();
  data.sub_win = subwin(data.win, 20, 12, 1, POS_GAME_X);
  data.sub_next = subwin(data.win,
			 (data.gamevar.maxheight > 6) ? data.gamevar.maxheight + 1 : 6,
			 (data.gamevar.maxwidth > 10) ? data.gamevar.maxwidth + 1 : 10,
			 1, POS_GAME_X + 15);
  noecho();
  keypad(stdscr, TRUE);
  data.keys = init_keys();
  init_keytab(&data.tabkey);
  nodelay(data.win, TRUE);

  if (has_colors() == FALSE)
    {
      endwin();
      return (my_putstr_err("Your terminal does not support color\n"));
    }
  if (*env == NULL)
    return (my_putstr_err("No environment detected\n"));
  /* opt = parse_params(ac, av); */

  srand(time(0));
  data.score.tab_score = init_tab(10, 20);
  init_tabscore(data.score.tab_score);

  /* if ((data.score.tab_score = init_tab(10, 20)) == NULL) */
  /*   return (my_putstr_err("Malloc error\n")); */


  start_color();
  my_init_color();
  curs_set(0);
  main_loop(&data, &opt);
  my_free_tab(data.score.tab_score);
  endwin();
  free_list(&data.tetriminos);
  return (0);
}
