##
## Makefile for  in /home/armin.pc/delivery/PSU_2016_minishell1
## 
## Made by Enguerrand Arminjon
## Login   <armin.pc@epitech.net>
## 
## Started on  Mon Jan  2 11:32:58 2017 Enguerrand Arminjon
## Last update Sun Feb 12 19:06:45 2017 Enguerrand Arminjon
##

SRCS 	=	srcs/my_putstr.c	\
		srcs/my_putchar.c	\
		srcs/my_put_nbr.c	\
		srcs/my_getnbr.c	\
		srcs/my_revstr.c	\
		srcs/my_printf.c	\
		srcs/my_printf2.c	\
		srcs/my_printf3.c	\
		srcs/my_printf4.c	\
		srcs/my_put_short.c	\
		srcs/my_put_long.c	\
		srcs/my_strcat.c	\
		srcs/my_strcmp.c	\
		srcs/my_strcmp_2.c	\
		srcs/my_str_isalpha.c	\
		srcs/my_str_isnum.c	\
		srcs/free_my_tab.c	\
		srcs/free_tab.c		\
		srcs/my_realloc.c	\
		srcs/get_next_line.c	\
		srcs/my_puterror.c	\
		print_tab.c		\
		navy.c			\
		tab_malloc.c		\
		put_in_boat.c		\
		put_in_boat_next.c	\
		dual_process.c		\
		my_strupper.c		\
		prompt.c		\
		info_navy.c		\
		signal.c		\
		recep.c			\
		space_tab_delete.c	\
		music.c			\
		print_info.c		\
		atk_on_map2.c		\
		my_cmds.c		\
		my_score.c		\
		my_new_signal.c		\
		main.c

OBJS 	=  	$(SRCS:.c=.o)

CFLAGS 	+=	-I include -Wall -Wextra

LDFLAGS +=	-I include -lncurses -lcsfml-audio -lcsfml-graphics

NAME 	=	navy

CC	= 	gcc

$(NAME): 	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

ALL:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re: 		fclean ALL

.PHONY:		ALL clean fclean re
