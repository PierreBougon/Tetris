/*
** key_event.c for KEYS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar  4 16:54:29 2016 bougon_p
** Last update Wed Mar 16 14:51:01 2016 Clémenceau Cedric
*/

#include "tetris.h"

int		get_key(t_data *data, char *key, char **keys, t_tabkey *tab_game)
{
  int           i;

  i = 0;
  if (data->pause == true && my_strcmp(key, keys[5]) != 0)
    return (time_pause(data));
  while (my_strcmp(key, keys[i]) != 0)
    {
      i++;
      if (i > 5)
        return (0);
    }
  return (tab_game->tabkey[i](data, &data->tetri_ig));
}

char			*my_get_key(char *str)
{
  struct termios	end;
  struct termios	start;
  char			buf[11];
  int			size;

  size = 0;
  while (buf[size])
    buf[size++] = 0;
  if ((ioctl(0, TCGETS, &start)) < 0)
    return (NULL);
  if ((ioctl(0, TCGETS, &end)) < 0)
    return (NULL);
  end.c_lflag &= ~ECHO;
  end.c_lflag &= ~ICANON;
  end.c_cc[VTIME] = 0;
  end.c_cc[VMIN] = 0;
  if ((ioctl(0, TCSETS, &end)) < 0)
    return (NULL);
  size = read(0, buf, 10);
  buf[size] = 0;
  if ((ioctl(0, TCSETS, &start)) < 0)
    return (NULL);
  my_strcpy(str, buf);
  return (str);
}
