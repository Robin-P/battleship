/*
** signal.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Feb  3 10:30:31 2017 Enguerrand Arminjon
** Last update Fri Feb  3 14:12:11 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "navy.h"

void		atk_on_map(char *atk, t_navy *navy, int nb)
{
  if (((navy->map[atk[1] - 47][(atk[0] - 64) * 2] == '.')
       || (navy->map[atk[1] - 47][(atk[0] - 64) * 2] == 'o')
       || (navy->map[atk[1] - 47][(atk[0] - 64) * 2] == 'x')))
    {
      usleep(5000);
      my_putstr("missed\n\n");
      if (navy->map[atk[1] - 47][(atk[0] - 64) * 2] == 'x')
	navy->map[atk[1] - 47][(atk[0] - 64) * 2] = 'x';
      else
	navy->map[atk[1] - 47][(atk[0] - 64) * 2] = 'o';
      if (nb == 1)
	kill(navy->usr1_pid, SIGUSR1);
      else
	kill(navy->usr2_pid, SIGUSR1);
    }
  else
    {
      usleep(5000);
      my_putstr("hit\n\n");
      navy->map[atk[1] - 47][(atk[0] - 64) * 2] = 'x';
      if (nb == 1)
	kill(navy->usr1_pid, SIGUSR2);
      else
	kill(navy->usr2_pid, SIGUSR2);
    }
}

int		send_signal_to_process(char *signal, int pid, int sig, int sig2)
{
  int		j;

  j = 'A';
  while (signal[0] - j >= 0)
    {
      usleep(5000);
      kill(pid, sig);
      j++;
    }
  j = '1';
  usleep(5000);
  kill(pid, sig2);
  while (signal[1] - j >= 0)
    {
      usleep(5000);
      kill(pid, sig);
      j++;
    }
  usleep(5000);
  kill(pid, sig2);
  return (0);
}

int		pid_null(t_navy *navy)
{
  static int	i;

  if (i == 0)
    {
      do_atk(navy->usr2_pid, navy);
      i = 1;
    }
  else
    {
      if ((end(navy->emap)) == 1)
	return (2);
      do_wait(navy, 2);
      print_map_navy(navy->map, navy->emap);
      i = 0;
    }
  return (0);
}

int		pid_no_null(t_navy *navy)
{
  static int	i;

  if (i == 1)
    {
      do_atk(navy->usr1_pid, navy);
      print_map_navy(navy->map, navy->emap);
      i = 0;
    }
  else
    {
      if ((end(navy->emap)) == 1)
	return (2);
      do_wait(navy, 1);
      i = 1;
    }
  return (0);
}

int		my_process_play(t_navy *navy, pid_t pid)
{
  signal(SIGUSR1, recep);
  signal(SIGUSR2, recep2);
  if (pid == 0)
    {
      if ((pid_null(navy)) == 2)
	return (2);
    }
  else if (pid != 0)
    {
      if ((pid_no_null(navy)) == 2)
	return (2);
    }
  return (0);
}
