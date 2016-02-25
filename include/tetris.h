/*
** tetris.h for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Feb 23 17:18:18 2016 bougon_p
** Last update Thu Feb 25 14:26:53 2016 Clémenceau Cedric
*/

#ifndef	TETRIS_H_
# define TETRIS_H_

# include "my.h"

# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <curses.h>
# include <dirent.h>
# include <sys/types.h>

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

typedef struct		s_score
{
  char			**tab_score;
  unsigned int		high_score;
}			t_score;

typedef struct		s_data
{
  char			***tetriminos;
  char			**tab_next;
  char			**tab_game;
  t_score		score;
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
char	***init_tetriminos(void);

#endif /* !TETRIS_H_ */
