/*
** stop_piece.c for stop in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Feb 28 00:52:14 2016 bougon_p
** Last update Wed Mar  2 00:18:36 2016 bougon_p
*/

#include "tetris.h"

/* int	check_colli(int n, int _n, int p, t_cdlist *tmp, t_tetri *itemdata) */
/* { */
/*   if ((itemdata->pos_x + n + p >= tmp->data->pos_x + p + _n */
/*        && itemdata->pos_x + n + p < */
/*        tmp->data->pos_x + tmp->data->width + p + _n) */
/*       && (tmp->data->item[0][p + _n] == '*' */
/* 	  && itemdata->item[itemdata->height - 1][p + n] == '*')) */
/*     return (1); */
/*   else */
/*     return (0); */
/* } */

/* int	search_n_pos(int n, int _n, t_tetri *itemdata, t_cdlist *tmp) */
/* { */
/*   if (itemdata->pos_x < tmp->data->pos_x) */
/*     { */
/*       while (itemdata->pos_x + n < tmp->data->pos_x) */
/* 	n++; */
/*       return (n); */
/*     } */
/*   else */
/*     { */
/*       while (itemdata->pos_x > tmp->data->pos_x + _n) */
/* 	_n++; */
/*       return (_n); */
/*     } */
/* } */

/* int		collision(t_tetri *itemdata, t_arglist *tetri_ig) */
/* { */
/*   int		i; */
/*   int		n; */
/*   int		_n; */
/*   int		p; */
/*   t_cdlist	*tmp; */

/*   tmp = tetri_ig->_root; */
/*   i = 0; */
/*   while (i++ < tetri_ig->length) */
/*     { */
/*       if (itemdata->pos_y + itemdata->height >= tmp->data->pos_y */
/* 	  && itemdata->pos_y + itemdata->height < tmp->data->pos_y + tmp->data->height) */
/* 	{ */
/* 	  _n = 0; */
/*  	  n = 0; */
/* 	  p = -1; */
/* 	  n = search_n_pos(n, _n, itemdata, tmp); */
/* 	  while (++p < itemdata->width && p < tmp->data->width) */
/* 	    if (check_colli(n, _n, p, tmp, itemdata) == 1) */
/* 	      return (1); */
/* 	} */
/*       tmp = tmp->next; */
/*     } */
/*   return (0); */
/* } */

int	need_to_stop(t_data *data, int refind)
{
  t_tetri       *itemdata;

  itemdata = data->tetri_ig._root->data;
  if ((itemdata->pos_y + itemdata->height + 1
       == data->gamevar.win_height && refind == 0))
      /* || collision(itemdata, &data->tetri_ig) == 1) */
    {
      return (1);
    }
  else
    return (0);
}
