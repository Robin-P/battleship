##
## Makefile for  in /home/armin.pc/delivery/PSU_2016_minishell1
## 
## Made by Enguerrand Arminjon
## Login   <armin.pc@epitech.net>
## 
## Started on  Mon Jan  2 11:32:58 2017 Enguerrand Arminjon
## Last update Sat Feb 11 18:18:31 2017 Enguerrand Arminjon
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
		srcs/print_tab.c	\
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
		main.c

OBJS 	=  	$(SRCS:.c=.o)

CFLAGS 	+=	-I include -Wall -Wextra

LDFLAGS +=	-I include

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
