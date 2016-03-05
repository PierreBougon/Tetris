##
## Makefile for TETRIS in /home/bougon_p/rendu/PSU_2015_tetris
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Tue Feb 23 17:06:22 2016 bougon_p
## Last update Sat Mar  5 16:37:33 2016 Clémenceau Cedric
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e


# SOURCES VARIABLES

MAIN		=	src/main/

TOOLS		=	src/tools/

INIT		=	src/init/

PRINT		=	src/print/

PIECE		=	src/piece/

ACTION		=	src/actions/

EVENT		=	src/event/

DEBUG		=	src/debug/

SRC		=	$(MAIN)tetris.c \
			$(MAIN)error.c \
			$(MAIN)fct_main.c \
			$(MAIN)free.c \
			$(MAIN)fill.c \
			$(INIT)init.c \
			$(INIT)init_tetri.c \
			$(INIT)initlist.c \
			$(INIT)init_keys.c \
			$(INIT)check.c \
			$(INIT)init_tabgame.c \
			$(PRINT)write_tetris.c \
			$(PRINT)print.c \
			$(PRINT)write_tetris2.c \
			$(PRINT)print_debug.c \
			$(PRINT)print_tetri.c \
			$(TOOLS)my_strcat.c \
			$(TOOLS)setnbr.c \
			$(TOOLS)my_strcpy.c \
			$(TOOLS)my_power.c \
			$(TOOLS)get_nl.c \
			$(TOOLS)set_line.c \
			$(PIECE)new_tetri.c \
			$(PIECE)print_piece.c \
			$(PIECE)move.c \
			$(PIECE)stop_piece.c \
			$(PIECE)actions.c \
			$(PIECE)collision.c \
			$(PIECE)full_line.c \
			$(ACTION)pause.c \
			$(ACTION)quit.c \
			$(EVENT)key_event.c \
			$(DEBUG)next.c \
			$(DEBUG)put_str_key.c \
			$(DEBUG)parsing.c \
			$(DEBUG)debug_functions.c

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH =	lib/

LIB	=	-lncurses

LDFLAGS =	-lmy -L$(LIBPATH) -lncurses


# PROJECT VARIABLES

NAME	=	tetris

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra -g $(IFLAG)

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
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
