/*
** tetris.h for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:18:18 2016 bougon_p
** Last update Tue Feb 23 19:03:12 2016 bougon_p
*/

#ifndef	TETRIS_H_
# define TETRIS_H_

# include "my.h"

# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include <ncurses.h>
# include <curses.h>

# define KEY_ESC 27

/*
** VAR PARSED BY PARSER
*/

typedef struct		s_options
{
  int			x;
}			t_options;

/*
** USEFUL GAME VARS
*/

typedef struct		s_data
{
  int			bite;
  int			coutal;
}			t_data;

/*
** AI functions
*/


/*
** Game functions
*/


/*
** Others fucntions
*/

int	my_putstr_err(char *);

#endif /* !TETRIS_H_ */
