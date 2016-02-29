/*
** init_keys.c for INIT KEYS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Feb 27 17:52:04 2016 bougon_p
** Last update Sun Feb 28 17:36:11 2016 Clémenceau Cedric
*/

#include "tetris.h"

int     *init_keys()
{
  int   *keys;

  if ((keys = malloc(sizeof(int) * 6)) == NULL)
    return (NULL);
  keys[0] = KEY_UP;
  keys[1] = KEY_DOWN;
  keys[2] = KEY_LEFT;
  keys[3] = KEY_RIGHT;
  keys[4] = KEY_ESC;
  keys[5] = KEY_SPACE;
  return (keys);
}

int     init_keytab(t_tabkey *tab)
{
  int   (**tabkey)(t_data *, t_arglist*);

  if ((tabkey = malloc(sizeof(t_tabkey) * 6)) == NULL)
    return (1);
  tabkey[0] = &turn_tetri;
  tabkey[1] = &drop;
  tabkey[2] = &move_left;
  tabkey[3] = &move_right;
  tabkey[4] = &quit;
  tabkey[5] = &m_pause;
  tab->tabkey = tabkey;
  return (0);
}
