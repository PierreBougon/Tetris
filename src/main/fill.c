/*
** fill.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sat Mar  5 15:15:23 2016 Clémenceau Cedric
** Last update Fri Mar 18 13:32:16 2016 bougon_p
*/

#include "tetris.h"

void	fill_to_check(t_data *data)
{
  my_strcpy(data->opt.to_check[0], "--help");
  my_strcpy(data->opt.to_check[1], "--debug");
  my_strcpy(data->opt.to_check[2], "-d");
  my_strcpy(data->opt.to_check[3], "--map-size=");
  my_strcpy(data->opt.to_check[4], "--without-next");
  my_strcpy(data->opt.to_check[5], "-w");
  my_strcpy(data->opt.to_check[6], "--level=");
  my_strcpy(data->opt.to_check[7], "-l");
  my_strcpy(data->opt.to_check[8], "-kl");
  my_strcpy(data->opt.to_check[9], "--key-left=");
  my_strcpy(data->opt.to_check[10], "-kr");
  my_strcpy(data->opt.to_check[11], "--key-right=");
  my_strcpy(data->opt.to_check[12], "-kt");
  my_strcpy(data->opt.to_check[13], "--key-turn=");
  my_strcpy(data->opt.to_check[14], "-kd");
  my_strcpy(data->opt.to_check[15], "--key-drop=");
  my_strcpy(data->opt.to_check[16], "-kq");
  my_strcpy(data->opt.to_check[17], "--key-quit=");
  my_strcpy(data->opt.to_check[18], "-kp");
  my_strcpy(data->opt.to_check[19], "--key-pause=");
}

void	fill_tab(t_data *data)
{
  data->tetris_tab[0] = help;
  data->tetris_tab[1] = debug_mode;
  data->tetris_tab[2] = debug_mode;
  data->tetris_tab[3] = map_size;
  data->tetris_tab[4] = without_next;
  data->tetris_tab[5] = without_next;
  data->tetris_tab[6] = level;
  data->tetris_tab[7] = level;
  data->tetris_tab[8] = keys_for_left;
  data->tetris_tab[9] = keys_for_left;
  data->tetris_tab[10] = keys_for_right;
  data->tetris_tab[11] = keys_for_right;
  data->tetris_tab[12] = keys_for_turn;
  data->tetris_tab[13] = keys_for_turn;
  data->tetris_tab[14] = keys_for_drop;
  data->tetris_tab[15] = keys_for_drop;
  data->tetris_tab[16] = keys_for_quit;
  data->tetris_tab[17] = keys_for_quit;
  data->tetris_tab[18] = keys_for_pause;
  data->tetris_tab[19] = keys_for_pause;
}

int	init_data_next(t_data *data)
{
  data->boole = 0;
  data->score.init_time = time(NULL);
  data->score.tpause = 0;
  data->score.tlastpause = 0;
  data->pause = false;
  data->score.score = 0;
  data->score.line = 0;
  if ((data->opt.to_check = init_tab(20, 14)) == NULL)
    return (1);
  fill_to_check(data);
  return (0);
}
