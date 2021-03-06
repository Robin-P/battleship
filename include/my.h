/*
** my.h for  in /home/armin.pc/delivery/CPool_Day09/include
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Fri Oct 14 08:36:11 2016 Enguerrand Arminjon
** Last update Sun Feb  5 16:10:13 2017 Enguerrand Arminjon
*/

#ifndef MY_H_
# define MY_H_

# include <sys/types.h>
# include <stdarg.h>
# include "navy.h"

/*
** Project's functions
*/

char	*space_tab_delete(char *str, int i, int a);
void	recep();
void	recep2();
void	atk_on_map(char *atk, t_navy *navy, int nb);
int	send_signal_to_process(char *signal, int pid, int sig, int sig2);
int	my_process_play(t_navy *navy, pid_t pid);
int	do_wait(t_navy *navy, int nb);
int	do_atk(int pid, t_navy *navy);
int	end(char **map);
char	**put_boat_vert(char **map, char *s);
int	print_map_navy(char **map, char **emap);
int	my_navy(t_navy *navy, pid_t pid, int nb);
char	*prompt_user();
char	*my_strupper(char *str);
int	dual_process(t_navy *navy, pid_t pid);
int	my_main_navy(char *str, pid_t pid);
char	**malloc_map(char **map);
char	**my_map_to_tab(char **map);
char	**put_boat(char **map, int fd);
void	print_tab(char **tab);
char	*get_next_line(int fd);

/*
** Other functions
*/

int	my_puterror(char *str, int canal, int ret);
char	**free_tab(char **tab);
char	my_strcmp(char *str_1, char *str_2);
char	my_strcpy(char *str_1, char *str_2);
char	*my_strcat(char *dest, char *src);
char	*my_realloc(char *str, int new_size);
void	for_my_pitch(int i, int zero);
int	my_size_c(int nb);
void	the_hashtag(char *s, va_list ap, int *a);
void	the_else_print(int *a);
void	the_flags(char *s, va_list ap, int *a);
void	my_octal(long int nb);
int	my_put_short(short nb);
int	my_printf(char *s, ...);
int	my_size(int nb);
void	my_binari(int nb);
void	my_hexadecimal(long int nb);
void	my_hexadecimal_2(long int nb);
int	my_putstr_int(int *str);
int	my_put_long(long int nb);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_str_isnum(char *str);

#endif /* !MY_H_ */
