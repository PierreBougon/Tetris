/*
** tetris.h for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:18:18 2016 bougon_p
** Last update Mon Feb 29 18:03:46 2016 bougon_p
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

# define POS_GAME_X 25
# define POS_GAME_Y 2

/*
** VAR PARSED BY PARSER
*/

typedef struct		s_options
{
  int			x;
}			t_options;

typedef	struct		s_gamevar
{
  int			win_width;
  int			win_height;
  int			speed;
  int			maxwidth;
  int			maxheight;
}			t_gamevar;

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
  int			init_time;
  int			act_time;
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
  t_gamevar		gamevar;
  char			**tab_next;
  char			**tab_game;
  t_score		score;
  WINDOW		*win;
  WINDOW		*sub_win;
  WINDOW		*sub_next;
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

float	need_to_move(t_data *, float);
int	need_to_stop(t_data *, int);
int	collision(t_tetri *, char **);

void	aff_layout(t_data *);
int	find_new_tetri(t_data *, int);
void	aff_piece(WINDOW *, t_arglist *);

/*
** Tab functions
*/

void	init_tabnext(t_data *, char **);
void	init_tabscore(char **);
void	init_tabgame_base(char **);


/*
** Others fucntions
*/

char	*my_strcpy(char *, char *);
char	*my_strncpy(char *, char *, int);
int	my_pow(int, int);
char	*setnbr(int);
char	*timesetnbr(int);
char	*my_strcat(char *, char *);
int	my_putstr_err(char *);
char	**init_tab(int, int);
int	init_tetriminos(t_arglist *);
int	*init_keys(void);
int	init_keytab(t_tabkey *);
void	check_max(t_data *);
char	*get_next_line(const int);
char	*set_line_null(char *, int);
int	my_strlen(char *);
void	init_tabgame(char **);

/*
** DEBUG MODE
*/

void	print_tetri(t_arglist *);

#endif /* !TETRIS_H_ */
