/*
** parsing.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Thu Mar  3 15:11:04 2016 Clémenceau Cedric
** Last update Fri Mar  4 20:03:29 2016 Clémenceau Cedric
*/

#include "tetris.h"

int	parsing_key(t_data *data, char *arg_parsed, char c)
{
  int	i;
  int	j;
  int	caract;

  i = 0;
  caract = 0;
  while (arg_parsed[i++] != c);
  j = i;
  if (c != '\0')
    {
      if ((data->opt.entered_key = my_strdup(&arg_parsed[i])) == NULL)
	return (1);
      while (arg_parsed[j])
	data->opt.entered_key[caract++] = arg_parsed[j++];
      data->opt.entered_key[caract] = 0;
    }
  arg_parsed[i] = 0;
  return (0);
}

int	parsing_arg_extanted(t_data *data, char **options, char c, int i)
{
  my_strcpy(data->opt.arg[i], options[i]);
  if ((parsing_key(data, data->opt.arg[i], c)) == 1)
    return (1);
  if (c == '\0')
    if ((data->opt.entered_key = my_strdup(options[++i])) == NULL)
      return (1);
  return (0);
}

int	parsing_arg(char **options, t_data *data)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (options[j++]);
  if ((data->opt.arg = init_tab(j, 14)) == NULL)
    return (1);
  while (options[++i])
    {
      if (options[i][0] == '-' && options[i][1] == '-')
	if ((parsing_arg_extanted(data, options, '=', i)) == 1)
	  return (1);
      if ((options[i][0] == '-' && options[i][1] == 'l') ||
	  (options[i][0] == '-' && options[i][1] == 'k') ||
      	  (options[i][0] == '-' && options[i][1] == 'w') ||
      	  (options[i][0] == '-' && options[i][1] == 'd'))
      	{
	  if ((parsing_arg_extanted(data, options, 0, i)) == 1)
	    return (1);
	  my_strcpy(data->opt.entered_key, options[++i]);
	  --i;
	}
    }
  return (0);
}

int			my_infinite_loop()
{
  struct termios	end;
  struct termios	start;
  char			c;

  if ((ioctl(0, TCGETS, &start)) < 0)
    return (1);
  end.c_lflag &= ~ECHO;
  end.c_lflag &= ~ICANON;
  end.c_cc[VMIN] = 1;
  if ((ioctl(0, TCSETS, &end)) < 0)
    return (1);
  read(0, &c, 1);
  if ((ioctl(0, TCSETS, &start)) < 0)
    return (1);
  return (0);
}
