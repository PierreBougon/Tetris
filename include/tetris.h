/*
** tetris.h for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:18:18 2016 bougon_p
** Last update Sat Feb 27 22:23:07 2016 bougon_p
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
# define KEY_SPACE ' '

# define POS_GAME 25

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
  int			pos_x;
  int			pos_y;
  char			**item;
}			t_tetri;

typedef struct		s_score
{
  char			**tab_score;
  int			high_score;
}			t_score;

typedef struct s_data t_data;

typedef struct  s_tabkey
{
  int           (**tabkey)(t_data *, t_arglist *);
}               t_tabkey;

typedef struct		s_data
{
  t_arglist		tetriminos;
  t_arglist		tetri_ig;
  char			**tab_next;
  char			**tab_game;
  t_score		score;
  WINDOW		*win;
  int			*keys;
  t_tabkey		tabkey;
}			t_data;


/*
** TETRIS letter functions
*/

void	write_tetris();	/* write letter and put color */
void	write_letter();
void	write_letter_e();
void	write_letter_t();
void	write_letter_r();
void	write_letter_i();
void	write_letter_s();


/*
** TETRIS functions color
*/

void	my_init_color();

/*
** Game functions
*/

int	turn_tetri(t_data *, t_arglist *);
int	drop(t_data *, t_arglist *);
int	move_left(t_data *, t_arglist *);
int	move_right(t_data *, t_arglist *);
int	quit(t_data *, t_arglist *);
int	m_pause(t_data *, t_arglist *);

void	aff_layout(t_data *);
int	find_new_tetri(t_data *, int);
void	aff_piece(t_arglist *);

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
int	*init_keys(void);
int	init_keytab(t_tabkey *);
char	*get_next_line(const int);
char	*set_line_null(char *, int);
int	my_strlen(char *);

/*
** DEBUG MODE
*/

void	print_tetri(t_arglist *);

#endif /* !TETRIS_H_ */
