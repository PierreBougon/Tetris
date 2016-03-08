/*
** tetris.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:12:05 2016 bougon_p
** Last update Mon Mar  7 15:22:16 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	key_event(t_data *data)
{
  int	key;

  key = getch();
  if (get_key(data, key, data->keys, &data->tabkey) == 1)
    return (1);
  return (0);
}

int	main_loop(t_data *data)
{
  int	refind;
  float	to_move;

  refind = -1;
  to_move = 0.0;
  while (1)
    {
      if ((protect_me(data)) == 1)
	return (1);
      if ((refresh()) == 1)
	return (1);
      if (data->pause == false)
	{
	  if ((refind = find_new_tetri(data, refind)) == -2)
	    return (1);
	  if (refind == -3)
	    return (-3);
	  aff_layout(data);
	  if (data->boole == 0)
	    if ((init_tabnext(data, data->tetri_ig.root->next->data)) == 1)
	      return (1);
	  aff_tetris(data);
	  to_move = need_to_move(data, to_move);
	  refind = need_to_stop(data, refind);
	  check_full_line(data);
	}
      if (key_event(data) == 1)
	break;
      usleep(10);
    }
  return (0);
}

int	check_arg(char **opt, t_data *data, int b)
{
  int	i;

  i = 1;
  while (opt[i])
    {
      if ((my_strcmp(data->opt.to_check[0], opt[i]) == 0) && b == 0)
	if ((data->tetris_tab[0](data, opt[0])) == 1)
	  return (1);
      if ((my_strcmp(data->opt.to_check[1], opt[i]) == 0 && b == 1) ||
	  (my_strcmp(data->opt.to_check[2], opt[i]) == 0 && b == 1))
	data->tetris_tab[1](data, data->opt.entered_key);
      i++;
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  t_data	data;
  int		r;
  int		err;

  if (*env == NULL)
    return (my_putstr_err("No environment detected\n"), 1);
  if ((r = setupterm(NULL, 0, &err)) == ERR)
    return (1);
  if ((init_data_next(&data)) == 1)
    return (1);
  if ((config_key(&data)) == 1)
    return (1);
  if ((init_data(&data, av, ac)) == 1)
    {
      endwin();
      return (1);
    }
  if ((config(&data)) == 1)
    return (1);
  my_free_tab(data.key);
  my_free_tab(data.score.tab_score);
  free_list(&data.tetriminos);
  if ((endwin()) == 1)
    return (1);
  return (0);
}
