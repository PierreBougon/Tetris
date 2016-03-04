/*
** tetris.h for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:18:18 2016 bougon_p
** Last update Fri Mar  4 20:34:09 2016 Clémenceau Cedric
*/

#ifndef	TETRIS_H_
# define TETRIS_H_

# define UNUSED(var) __attribute__((unused))

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
# include <termios.h>
# include <sys/ioctl.h>
# include <stdbool.h>

/*
** DEFINES
*/

# define KEY_ESC 27
# define KEY_SPACE ' '

# define POS_GAME_X 25
# define POS_GAME_Y 2

/*
** VAR PARSED BY PARSER
*/

typedef	struct		s_gamevar
{
  int			level;
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
  char			*name;
  char			**item;
}			t_tetri;

typedef struct		s_score
{
  char			**tab_score;
  int			high_score;
  int			score;
  int			init_time;
  int			act_time;
  int			init_tpause;
  int			tpause;
  int			tlastpause;
  int			move_bonus;
}			t_score;
typedef struct s_data t_data;

typedef struct  s_tabkey
{
  int           (**tabkey)(t_data *, t_arglist *);
}               t_tabkey;

typedef struct		s_opt
{
  char			**arg;
  char			*entered_key;
}			t_opt;

typedef struct		s_data
{
  struct termios	start;
  WINDOW		*win;
  WINDOW		*sub_win;
  WINDOW		*sub_next;
  t_arglist		tetriminos;
  t_arglist		tetri_ig;
  t_gamevar		gamevar;
  t_tabkey		tabkey;
  t_score		score;
  t_opt			opt;
  char			**key;
  int			**tab_game;
  int			*keys;
  int			boole;
  bool			pause;
}			t_data;

/*
** Debug Mode
*/

int	my_infinite_loop();
int	parsing_arg(char **, t_data *);
int	config_key(t_data *);
void	my_putstr_keys(t_data *);
void	my_putstr_keys_suite(t_data *);
int	help(t_data *, char *);
void    boole_next(t_data *, char *);
void	aff_next(t_data *);
void	aff_keys(t_data *);
void	my_show_list(t_arglist *);
void	aff_tetriminos(t_data *);
void	debug_mode(t_data *, char *);
int	init_data(t_data *, char **, int);
int	my_check_option(t_data *, char **);

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
int	collision(t_tetri *, int **);
int	collision_left(t_tetri *, int **);
int	collision_right(t_tetri *, int **);
int	collision_drop(t_tetri *, int **, int);
void	check_full_line(t_data *);

void	aff_layout(t_data *);
int	find_new_tetri(t_data *, int);
void	aff_piece(WINDOW *, t_arglist *);

int	time_pause(t_data *);


/*
** Events
*/

int	get_key(t_data *, int, int *, t_tabkey *);

/*
** Tab functions
*/

void	init_tabnext(t_data *, t_tetri *);
void	init_tabscore(char **);
void	init_tabgame_base(char **);


/*
** Others fucntions
*/

int	main_loop(t_data *);
char	*my_strdup(char *);
int	config(t_data *);
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
int	**init_tab_game(int, int);
void	check_max(t_data *);
char	*get_next_line(const int);
char	*set_line_null(char *, int);
int	my_strlen(char *);
void	init_tabgame(char **);
void	my_free_tab(char **);

/*
** Print functions
*/

void	protect_me(t_data *);
int     aff_tetris(t_data *);

#endif /* !TETRIS_H_ */
