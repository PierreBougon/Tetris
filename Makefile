##
## Makefile for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Tue Feb 23 17:06:22 2016 bougon_p
## Last update Tue Feb 23 22:49:38 2016 bougon_p
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e


# SOURCES VARIABLES

MAIN		=	src/main/

SRC		=	$(MAIN)tetris.c \
			$(MAIN)error.c \
			$(MAIN)print.c

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH =	lib/

LIB	=	-lncurses

LDFLAGS =	-lmy -L$(LIBPATH) -lncurses


# PROJECT VARIABLES

NAME	=	tetris

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Werror -Wextra -ansi -pedantic $(IFLAG)

CC      =	gcc $(CFLAGS)



# PROJECT RULES

$(NAME)		: 	$(OBJS)
			@$(ECHO) "$(GREEN)\n> Compiling project\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all		:	$(NAME) 

clean		:
			@$(RM) $(OBJS)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)> $<\t : \t [OK]$(WHITE)"
