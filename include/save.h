/*
** get_next_line.h for get_nl in /home/clemen_j/Work/CPE/CPE_2015_getnextline
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Jan  4 11:18:22 2016 Clémenceau Cedric
** Last update Sat Feb 27 19:45:52 2016 bougon_p
*/

#ifndef GETNLINE_H_
# define GETNLINE_H_

#ifndef READ_SIZE
# define READ_SIZE (100)
#endif /* !READ_SIZE */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct	s_info
{
  int		readed;
  char		*str;
  int		j;
}		t_info;

#endif /* !GETNLINE_H_ */
