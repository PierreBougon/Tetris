/*
** struct.h for STRUCT in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar  8 08:36:12 2016 bougon_p
** Last update Thu Mar 10 20:13:18 2016 Clémenceau Cedric
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <stdbool.h>
# include <ncurses.h>
# include <curses.h>

/*
** VAR PARSED BY PARSER
*/

typedef struct		s_gamevar
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
  bool			error;
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
  int			line;
}			t_score;


typedef struct s_data t_data;

typedef struct	s_tabkey
{
  int		(**tabkey)(t_data *, t_arglist *);
}		t_tabkey;

typedef struct		s_opt
{
  char			**to_check;
  char			**arg;
  char			**key_to_set;
  char			*entered_key;
}			t_opt;

typedef struct		s_data
{
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
  int			refind;
  float			to_move;
  int			(**tetris_tab)(t_data *, char *);
}			t_data;

#endif /* !STRUCT_H_  */
