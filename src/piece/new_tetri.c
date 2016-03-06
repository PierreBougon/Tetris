/*
** new_tetri.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Feb 26 13:44:01 2016 bougon_p
** Last update Sun Mar  6 16:58:45 2016 bougon_p
*/

#include "tetris.h"

char		**strcopy2d(char **dest, char **src, t_tetri *tetri)
{
  int		i;
  int		j;
  int		size;

  size = (tetri->height > tetri->width) ? tetri->height : tetri->width;
  dest = init_tab(size, size);
  j = -1;
  while (++j < size)
    {
      i = -1;
      while (++i < size)
	dest[j][i] = 0;
    }
  j = -1;
  while (++j < tetri->height)
    {
      i = -1;
      while (++i < tetri->width)
	dest[j][i] = src[j][i];
    }
  return (dest);
}

void		chose_tetri(t_data *data, t_tetri *tetri, t_arglist *tetriminos)
{
  int		i;
  int		j;
  t_cdlist	*tmp;

  i = rand() % tetriminos->length;
  j = 0;
  tmp = tetriminos->root;
  while (j++ < i)
    {
      tmp = tmp->next;
    }
  while (tmp->data->error == true)
    tmp = tmp->next;
  tetri->width = tmp->data->width;
  tetri->height = tmp->data->height;
  tetri->color = tmp->data->color;
  tetri->pos_x = rand() % (data->gamevar.win_width - tetri->width + 1) + 1;
  tetri->pos_y = 1;
  tetri->item = strcopy2d(tetri->item, tmp->data->item, tmp->data);
}

int	find_new_tetri(t_data *data, int refind)
{
  t_tetri	*tetri;

  if (refind == -1)
    {
      if ((tetri = malloc(sizeof(t_tetri))) == NULL)
	return (-2);
      chose_tetri(data, tetri, &data->tetriminos);
      create_cdlist(&data->tetri_ig, tetri);
      if ((tetri = malloc(sizeof(t_tetri))) == NULL)
      	return (-2);
      chose_tetri(data, tetri, &data->tetriminos);
      add_last_cdl(&data->tetri_ig, tetri);
      refind = 0;
    }
  else if (refind != 0)
    {
      if ((tetri = malloc(sizeof(t_tetri))) == NULL)
      	return (-2);
      data->score.move_bonus = 1;
      chose_tetri(data, tetri, &data->tetriminos);
      my_free_tab(data->tetri_ig.root->data->item);
      free(data->tetri_ig.root->data);
      data->tetri_ig.root->data = tetri;
      data->tetri_ig.root = data->tetri_ig.root->next;
      refind = 0;
      if (check_end_game(data) == 1)
	return (-3);
    }
  return (refind);
}
