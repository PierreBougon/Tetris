/*
** list.h for LISTS in /home/bougon_p/rendu/PSU_2015_tetris
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 25 15:00:09 2016 bougon_p
** Last update Thu Mar 10 19:38:40 2016 bougon_p
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

int	create_cdlist(t_arglist *, void *);
int	add_first_cdl(t_arglist *, void *);
int	add_last_cdl(t_arglist *, void *);
int	free_list(t_arglist *);

#endif /* !LIST_H_ */
