/*
** tetris.h for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:18:18 2016 bougon_p
** Last update Thu Feb 25 21:58:37 2016 bougon_p
*/

#ifndef	TETRIS_H_
# define TETRIS_H_

# include "list.h"
# include "my.h"
# include "get_next_line.h"

# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <curses.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <ncurses.h>
# include <curses.h>

# define KEY_ESC 27
# define POS_GAME 30

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

typedef struct		s_tetri
{
  int			width;
  int			height;
  int			color;
  char			**item;
}			t_tetri;

typedef struct		s_score
{
  char			**tab_score;
  unsigned int		high_score;
}			t_score;

typedef struct		s_data
{
  t_arglist		tetriminos;
  char			**tab_next;
  char			**tab_game;
  t_score		score;
}			t_data;

/*
** TETRIS letter functions
*/
void	write_tetris();
void	write_letter();
void	write_letter_e();
void	write_letter_t();
void	write_letter_r();
void	write_letter_i();
void	write_letter_s();

/*
** Game functions
*/

void	aff_layout(t_data *);

/*
** Others fucntions
*/

char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
int	my_pow(int, int);
char	*setnbr(int);
char	*my_strcat(char *, char *);
int	my_putstr_err(char *);
char	**init_tab(int, int);
int	init_tetriminos(t_arglist *);
char	*get_next_line(const int);
char	*set_line_null(char *, int);

/*
** DEBUG MODE
*/

void	print_tetri(t_arglist *);

#endif /* !TETRIS_H_ */
