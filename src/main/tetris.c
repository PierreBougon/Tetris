/*
** tetris.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:12:05 2016 bougon_p
** Last update Thu Mar  3 14:25:36 2016 Clémenceau Cedric
*/

#include "tetris.h"

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

int	main_loop(t_data *data)
{
  int	key;
  int	refind;
  float	to_move;

  refind = -1;
  to_move = 0;
  while (1)
    {
      refresh();
      if ((refind = find_new_tetri(data, refind)) == -2)
	return (1);
      aff_layout(data);
      if (data->boole == 0)
	init_tabnext(data, data->tetri_ig._root->next->data);
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
  while (tab[i] != NULL)
    {
      dprintf(2, "tab[%d] = %s\n", i, tab[i]);
      free(tab[i++]);
    }
  free(tab);
}

int	main(int ac, char **av, char **env)
{
  t_data	data;

  data.boole = 0;
  if ((config_key(&data)) == 1)
    return (1);
  if (*env == NULL)
    return (my_putstr_err("No environment detected\n"));
  data.score.init_time = time(NULL);
  if ((init_data(&data, av, ac)) == 1)
    return (1);
  if ((config(&data)) == 1)
    return (1);
  my_free_tab(data.score.tab_score);
  endwin();
  free_list(&data.tetriminos);
  my_free_tab(data.key);
  return (0);
}
