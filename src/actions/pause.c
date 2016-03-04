/*
** pause.c for PAUSE in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar  4 14:21:22 2016 bougon_p
** Last update Fri Mar  4 14:31:22 2016 bougon_p
*/

#include "tetris.h"

int	time_pause(t_data *data)
{
  data->score.tpause =
    time(NULL) - data->score.init_tpause + data->score.tlastpause;
  return (0);
}

int	m_pause(t_data *data, t_arglist *tetri_ig)
{

  tetri_ig = tetri_ig;
  if (data->pause == FALSE)
    {
      data->pause = TRUE;
      data->score.init_tpause = time(NULL);
    }
  else
    {
      data->pause = FALSE;
      data->score.tlastpause = data->score.tpause;
    }
  return (0);
}
