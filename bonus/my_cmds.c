/*
** my_nuke.c for  in /home/armin.pc/delivery/PSU_2016_navy/bonus
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Sat Feb 11 10:40:40 2017 Enguerrand Arminjon
** Last update Sun Feb 12 19:05:30 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "navy.h"

int	my_nuke_send(t_navy *navy, pid_t pid)
{
  int	i;
  int	j;

  i = 2;
  play_my_nuke_send(navy);
  while (navy->emap[i] != '\0')
    {
      j = 2;
      while (navy->emap[i][j] != '\0')
	{
	  navy->emap[i][j] = 'x';
	  j++;
	}
      i++;
    }
  send_signal_to_process("G9", pid, SIGUSR1, SIGUSR2);
  return (2);
}

int	my_nuke_add(t_navy *navy)
{
  int	i;
  int	j;

  i = 2;
  play_my_nuke_add(navy);
  while (navy->map[i] != '\0')
    {
      j = 2;
      while (navy->map[i][j] != '\0')
	{
	  navy->map[i][j] = 'x';
	  j++;
	}
      i++;
    }
  return (1);
}

int	my_main_cmds_add(t_navy *navy, char *recep_atk)
{
  if (my_strcmp(recep_atk, "G9") == 0)
    return (my_nuke_add(navy));
  else if (my_strcmp(recep_atk, "H9") == 0)
    return (2);
  return (0);
}

int	my_main_cmds_send(t_navy *navy, pid_t pid, char *atk_pos)
{
  if (my_strcmp(atk_pos, "/nuke") == 0)
    return (my_nuke_send(navy, pid));
  else if (my_strcmp(atk_pos, "/exit") == 0)
    {
      send_signal_to_process("H9", pid, SIGUSR1, SIGUSR2);
      return (1);
    }
  else if (my_strcmp(atk_pos, "/sigint") == 0)
    {
      send_signal_to_process("J1", pid, SIGUSR1, SIGUSR2);
      return (1);
    }
  return (0);
}
