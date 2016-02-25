/*
** set_line.c for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 25 16:22:56 2016 bougon_p
** Last update Thu Feb 25 16:23:15 2016 bougon_p
*/

char	*set_line_null(char *str, int length)
{
  int   i;

  i = -1;
  while (++i < length)
    str[i] = 0;
  return (str);
}
