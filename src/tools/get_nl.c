/*
** get2.c for nextline in /home/bougon_p/rendu/CPE_2015_getnextline
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Jan 12 15:50:10 2016 bougon_p
** Last update Thu Feb 25 00:22:58 2016 bougon_p
*/

#include <stdio.h>
#include "get_next_line.h"

char	*my_realloc(char *line)
{
  char	*new_line;
  int	size;
  int	i;

  i = 0;
  size = 0;
  while (line[size] != 0 && line[size] != EOF)
    size++;
  if ((new_line = malloc(sizeof(char) * (size + READ_SIZE) + 2)) == NULL)
    return (NULL);
  while (i < size)
    {
      new_line[i] = line[i];
      i++;
    }
  while (i < (size + READ_SIZE + 2))
    new_line[i++] = 0;
  free(line);
  return (new_line);
}

char	*save_buf(char *buf, int i)
{
  char	*nextline;
  int	p;

  p = 0;
  if ((nextline = malloc((sizeof(char) * (READ_SIZE - i)) + 1)) == NULL)
    return (NULL);
  i++;
  while (i < READ_SIZE && buf[i] != 0)
    nextline[p++] = buf[i++];
  nextline[p] = 0;
  free(buf);
  return (nextline);
}

char	*end_ofline(char **next_line, t_file *file, int i)
{
  *next_line = save_buf(file->buf, i);
  return (file->line);
}

char	*fill_line(t_file *file, const int fd, char **next_line)
{
  int		i;

  file->nb_char = 1;
  while (file->count = 0, file->nb_char != 0)
    {
      if ((file->nb_char = read(fd, file->buf, READ_SIZE)) == -1
	  || (file->nb_char == 0 && file->count == 0) || file->buf == NULL)
	return (NULL);
      i = 0;
      if (file->nb_char == 0)
	return (end_ofline(next_line, file, i));
      while (i < file->nb_char)
      	{
      	  if (file->buf[i] == '\n')
	    return (end_ofline(next_line, file, i));
	  file->line[file->p] = file->buf[i];
      	  i++, file->p++;
      	}
      if ((file->line = my_realloc(file->line)) == NULL)
	return (NULL);
      file->count++;
    }
  free(file->buf);
  return (file->buf);
}

char	*get_next_line(const int fd)
{
  t_file	file;
  static char	*next_line;

  file.p = 0;
  if (next_line != NULL)
    {
      file.line = next_line;
      if ((file.line = my_realloc(file.line)) == NULL)
      	return (NULL);
      while (file.line[file.p] != 0 && file.line[file.p] != EOF)
	file.p++;
    }
  else
    {
      if ((file.line = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
	return (NULL);
    }
  if ((file.buf = malloc(sizeof(char) * READ_SIZE)) == NULL)
    return (NULL);
  return (fill_line(&file, fd, &next_line));
}
