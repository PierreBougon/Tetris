/*
** tetris.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:12:05 2016 bougon_p
** Last update Sun Mar  6 16:01:07 2016 bougon_p
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
      protect_me(data);
      refresh();
      if (data->pause == false)
	{
	  if ((refind = find_new_tetri(data, refind)) == -2)
	    return (1);
	  if (refind == -3)
	    return (-3);
	  aff_layout(data);
	  if (data->boole == 0)
	    init_tabnext(data, data->tetri_ig.root->next->data);
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

int	main(int ac, char **av, char **env)
{
  t_data	data;

  if ((init_data_next(&data)) == 1)
    return (1);
  if ((config_key(&data)) == 1)
    return (1);
  if (*env == NULL)
    return (my_putstr_err("No environment detected\n"));
  if ((init_data(&data, av, ac)) == 1)
    return (1);
  if ((config(&data)) == 1)
    return (1);
  my_free_tab(data.key);
  my_free_tab(data.score.tab_score);
  free_list(&data.tetriminos);
  endwin();
  return (0);
}
