/*
** init_keys.c for INIT KEYS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Feb 27 17:52:04 2016 bougon_p
** Last update Sat Mar 12 15:51:52 2016 bougon_p
*/

#include "tetris.h"

int	init_keytab(t_tabkey *tab_key)
{
  int	(**tabkey)(t_data *, t_arglist*);

  if ((tabkey = malloc(sizeof(t_tabkey) * 6)) == NULL)
    return (1);
  tabkey[0] = &turn_tetri;
  tabkey[1] = &drop;
  tabkey[2] = &move_left;
  tabkey[3] = &move_right;
  tabkey[4] = &quit;
  tabkey[5] = &m_pause;
  tab_key->tabkey = tabkey;
  return (0);
}
