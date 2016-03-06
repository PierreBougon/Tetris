/*
** fill.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Sat Mar  5 15:15:23 2016 Clémenceau Cedric
** Last update Sun Mar  6 20:40:59 2016 Clémenceau Cedric
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
  my_strcpy(data->opt.to_check[10], "--level=");
  my_strcpy(data->opt.to_check[6], "-kd");
  my_strcpy(data->opt.to_check[7], "-kq");
  my_strcpy(data->opt.to_check[8], "-kp");
  my_strcpy(data->opt.to_check[9], "-kt");
  my_strcpy(data->opt.to_check[11], "--key-left=");
  my_strcpy(data->opt.to_check[12], "--key-right=");
  my_strcpy(data->opt.to_check[13], "--key-turn=");
  my_strcpy(data->opt.to_check[14], "--key-drop=");
  my_strcpy(data->opt.to_check[15], "--key-quit=");
  my_strcpy(data->opt.to_check[16], "--key-pause=");
  my_strcpy(data->opt.to_check[17], "-kl");
  my_strcpy(data->opt.to_check[18], "-kr");
  my_strcpy(data->opt.to_check[19], "-l");
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
  /* tetris_tab[2] = key_left; */
  /* tetris_tab[3] = key_right; */
  /* tetris_tab[4] = key_turn; */
  /* tetris_tab[5] = key_drop; */
  /* tetris_tab[6] = key_quit; */
  /* tetris_tab[7] = key_pause; */
}

int     init_data_next(t_data *data)
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
