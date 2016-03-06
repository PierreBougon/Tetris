/*
** parsing.c for tetris in /home/clemen_j/Work/PSU/PSU_2015_tetris
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Thu Mar  3 15:11:04 2016 Clémenceau Cedric
** Last update Sun Mar  6 17:05:35 2016 Clémenceau Cedric
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

int	parse_without_key(t_data * data, char **opt, int *i)
{
  if ((opt[(*i)][0] == '-' && opt[(*i)][1] == 'd') ||
      (opt[(*i)][0] == '-' && opt[(*i)][1] == 'w') ||
      (opt[(*i)][0] == '-' && opt[(*i)][1] == '-' && opt[(*i)][2] == 'h') ||
      (opt[(*i)][0] == '-' && opt[(*i)][1] == '-' && opt[(*i)][2] == 'd') ||
      (opt[(*i)][0] == '-' && opt[(*i)][1] == '-' && opt[(*i)][2] == 'w'))
    my_strcpy(data->opt.arg[(*i)], opt[(*i)]);
  else if ((opt[*i][0] == '-' && opt[*i][1] == '-' && opt[*i][2] == 'k') ||
	   (opt[*i][0] == '-' && opt[*i][1] == '-' && opt[*i][2] == 'l') ||
	   (opt[*i][0] == '-' && opt[*i][1] == '-' && opt[*i][2] == 'm'))
    {
      if ((parsing_arg_extanted(data, opt, '=', (*i))) == 1)
	return (1);
    }
  else if ((opt[(*i)][0] == '-' && opt[(*i)][1] == 'l' && opt[(*i) + 1]) ||
	   (opt[(*i)][0] == '-' && opt[(*i)][1] == 'k' && opt[(*i) + 1]))
    {
      if ((parsing_arg_extanted(data, opt, 0, (*i))) == 1)
	return (1);
      my_strcpy(data->opt.entered_key, opt[++(*i)]);
    }
  else
    return (my_putstr("Wrong arguments\n"), 1);
  return (0);
}

int	parsing_arg(char **opt, t_data *data)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (opt[j++]);
  if ((data->opt.arg = init_tab(j, 15)) == NULL)
    return (1);
  while (opt[++i])
    if ((parse_without_key(data, opt, &i)) == 1)
      return (1);
  return (0);
}

int			my_infinite_loop()
{
  struct termios	end;
  struct termios	start;
  char			c;

  if ((ioctl(0, TCGETS, &start)) < 0)
    return (1);
  if ((ioctl(0, TCGETS, &end)) < 0)
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
