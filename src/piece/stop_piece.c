/*
** stop_piece.c for stop in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Feb 28 00:52:14 2016 bougon_p
** Last update Mon Feb 29 20:09:59 2016 bougon_p
*/

#include "tetris.h"

/* int	collision(t_tetri *itemdata, char **tab_game) */
/* { */
/*   endwin(); */
/*   printf("posmaxy = %d, posmaxx = %d, \n" */
/* 	 , itemdata->height + , itemdata->width); */
/*   return (0); */
/* } */

int	need_to_stop(t_data *data, int refind)
{
  t_tetri       *itemdata;

  itemdata = data->tetri_ig._root->data;
  if (itemdata->pos_y + itemdata->height + 1
      == data->gamevar.win_height && refind == 0)
    {
      return (1);
    }
  else
    return (0);
}
