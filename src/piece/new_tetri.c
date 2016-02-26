/*
** new_tetri.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Feb 26 13:44:01 2016 bougon_p
** Last update Fri Feb 26 17:45:22 2016 bougon_p
*/

#include "tetris.h"

char		**strcopy2d(char **dest, char **src, t_tetri *tetri)
{
  int		i;
  int		j;

  dest = init_tab(tetri->height, tetri->width);
  j = -1;
  while (++j < tetri->height)
    {
      i = -1;
      while (++i < tetri->width)
	{
	  dest[j][i] = src[j][i];
	}
    }
  return (dest);
}

void		chose_tetri(t_tetri *tetri, t_arglist *tetriminos)
{
  int		i;
  int		j;
  t_cdlist	*tmp;

  i = rand() % tetriminos->length;
  j = 0;
  tmp = tetriminos->root;
  while (j++ < i)
    tmp = tmp->next;
  tetri->width = tmp->data->width;
  tetri->height = tmp->data->height;
  tetri->color = tmp->data->color;

  tetri->item = strcopy2d(tetri->item, tmp->data->item, tmp->data);

}

int	find_new_tetri(t_data *data, int refind)
{
  t_tetri	*tetri;

  if (refind == -1)
    {
      if ((tetri = malloc(sizeof(t_cdlist))) == NULL)
	return (-2);
      chose_tetri(tetri, &data->tetriminos);
      create_cdlist(&data->tetri_ig, tetri);
      if ((tetri = malloc(sizeof(t_cdlist))) == NULL)
      	return (-2);
      chose_tetri(tetri, &data->tetriminos);
      add_last_cdl(&data->tetri_ig, tetri);
      refind = 0;
    }
  else if (refind == 0)
    refind = 0;
  else
    {
      if ((tetri = malloc(sizeof(t_cdlist))) == NULL)
      	return (-2);
      chose_tetri(tetri, &data->tetriminos);
      data->tetri_ig.root = data->tetri_ig.root->next;
      data->tetri_ig.root->next->data = tetri;
      refind = 0;
    }
  return (refind);
}
