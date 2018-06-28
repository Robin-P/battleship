/*
** music.c for  in /home/armin.pc/delivery/PSU_2016_navy/bonus
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Feb 10 13:11:37 2017 Enguerrand Arminjon
** Last update Sat Feb 11 18:25:22 2017 Enguerrand Arminjon
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"

int		play_my_music(t_navy *navy, char *atk_pos, pid_t pid)
{
  sfMusic_play(navy->tab_m[0]);
  sleep(1);
  send_signal_to_process(atk_pos, pid, SIGUSR1, SIGUSR2);
  return (0);
}

int		play_my_nuke_send(t_navy *navy)
{
  sfMusic_play(navy->tab_m[0]);
  sleep(1);
  return (0);
}

int		play_my_nuke_add(t_navy *navy)
{
  sfMusic_play(navy->tab_m[4]);
  sleep(22);
  sfMusic_play(navy->tab_m[3]);
  sleep(3);
  return (1);
}
