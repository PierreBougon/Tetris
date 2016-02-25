/*
** list.h for LISTS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 25 15:00:09 2016 bougon_p
** Last update Thu Feb 25 19:12:23 2016 bougon_p
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct		s_cdlist
{
  struct s_tetri	*data;
  struct s_cdlist	*prev;
  struct s_cdlist	*next;
}			t_cdlist;

typedef struct		s_arglist
{
  int			length;
  t_cdlist		*root;
}			t_arglist;

int	create_cdlist(t_arglist *arg, void *);
int	add_first_cdl(t_arglist *arg, void *);
int	add_last_cdl(t_arglist *arg, void *);
int	free_list(t_arglist *arg);

#endif /* !LIST_H_ */
