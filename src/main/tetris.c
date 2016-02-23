/*
** tetris.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:12:05 2016 bougon_p
** Last update Wed Feb 24 00:41:24 2016 Clémenceau Cedric
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
      aff_layout(&data->score);
      key = getch();
      if (key == KEY_ESC)
      	break;
    }
  return (0);
}

char	**init_tab(int line, int col)
{
  char	**tab;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (NULL);
  tab[line] = NULL;
  while (i < line)
    {
      if ((tab[i] = malloc(sizeof(char) * col + 1)) == NULL)
	return (NULL);
      tab[col] = 0;
      i++;
    }
  return (tab);
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
  start_color();
  curs_set(0);
  main_loop(&data, &opt);
  endwin();
  return (0);
}
