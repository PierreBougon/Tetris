/*
** get_next_line.c for get_nl in /home/clemen_j/Work/CPE/CPE_2015_getnextline
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Jan  4 11:17:55 2016 Clémenceau Cedric
** Last update Sat Feb 27 19:20:48 2016 bougon_p
*/

#include "get_next_line.h"
#include "tetris.h"

char	*my_realloc(char *ptr, int size)
{
  char	*dest;
  int	i;
  int	restat;

  restat = 0;
  i = -1;
  if (ptr == NULL)
    {
      if ((ptr = malloc(size + 1)) == NULL)
	return (NULL);
      while (restat < size)
	ptr[restat++] = 0;
      return (ptr);
    }
  while (ptr[++i]);
  if ((dest = malloc(i + READ_SIZE + 2)) == NULL)
    return (NULL);
  i = -1;
  while (ptr[++i])
    dest[i] = ptr[i];
  dest[i + 1] = 0;
  free(ptr);
  return (dest);
}

int	check(char *buff)
{
  int	i;

  i = 0;
  if (buff == NULL)
    return (0);
  while (buff[i])
    {
      if (buff[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

char	*complete_my_buff(char *buff, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (buff[i])
    i++;
  while (str[j])
    {
      buff[i] = str[j];
      i++;
      j++;
    }
  buff[i] = 0;
  return (buff);
}

char	*check_buff(char *buff)
{
  char	*str;
  int	i;

  i = -1;
  while (buff[++i]);
  if ((str = malloc(i + 2)) == NULL)
    return (NULL);
  i = -1;
  while (buff[++i] != '\n' && buff[i])
    str[i] = buff[i];
  str[i + 1] = 0;
  return (str);
}

char	*get_next_line(const int fd)
{
  static char	*buff = NULL;
  char		str[READ_SIZE + 1];
  char		*to_write;
  int		readed;

  readed = 0;
  str[0] = 0;
  while (check(buff) == 0)
    {
      readed = read(fd, str, READ_SIZE);
      if (readed < 1)
	return (buff);
      str[readed] = 0;
      if ((buff = my_realloc(buff, readed)) == NULL)
	return (NULL);
      buff = complete_my_buff(buff, str);
    }
  if ((to_write = check_buff(buff)) == NULL)
    return (NULL);
  buff = &buff[my_strlen(to_write) + 1];
  if (buff[0] == 0)
    buff = NULL;
  return (to_write);
}
