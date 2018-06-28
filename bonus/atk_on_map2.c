/*
** atk_on_map2.c for  in /home/armin.pc/delivery/PSU_2016_navy/bonus
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Fri Feb 10 13:26:35 2017 Enguerrand Arminjon
** Last update Sat Feb 11 18:25:43 2017 Enguerrand Arminjon
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "navy.h"

int		atk_on_map2(char *atk, t_navy *navy, int nb)
{
  my_putstr(RED "hit\n\n" WHITE);
  sfMusic_play(navy->tab_m[1]);
  usleep(5000);
  navy->map[atk[1] - 47][(atk[0] - 64) * 2] = 'x';
  if (nb == 1)
    kill(navy->usr1_pid, SIGUSR2);
  else
    kill(navy->usr2_pid, SIGUSR2);
  return (0);
}
