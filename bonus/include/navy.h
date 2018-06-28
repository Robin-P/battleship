/*
** navy.h for  in /home/armin.pc
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Nov  7 11:32:08 2016 Enguerrand Arminjon
** Last update Sat Feb 11 15:28:12 2017 Enguerrand Arminjon
*/

#ifndef NAVY_H_
# define NAVY_H_

# include <signal.h>
# include <SFML/Audio.h>
# include <SFML/Graphics.h>

typedef struct	s_navy
{
  sfMusic	**tab_m;
  pid_t		usr1_pid;
  pid_t		usr2_pid;
  char		**map;
  char		**emap;
  int		score;
  int		last_hit;
  int		hit;
  int		miss;
}		t_navy;

typedef struct	s_signal
{
  int		my_sig1;
  int		my_sig2;
  int		my_sigend;

}		t_signal;

#endif /* !NAVY_H_ */
