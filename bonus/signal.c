/*
** signal.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Feb  3 10:30:31 2017 Enguerrand Arminjon
** Last update Sun Feb 12 19:01:46 2017 Enguerrand Arminjon
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "navy.h"

int		atk_on_map(char *atk, t_navy *navy, int nb)
{
  usleep(5000);
  if (((navy->map[atk[1] - 47][(atk[0] - 64) * 2] == '.')
       || (navy->map[atk[1] - 47][(atk[0] - 64) * 2] == 'o')
       || (navy->map[atk[1] - 47][(atk[0] - 64) * 2] == 'x')))
    {
      my_putstr(CYAN "missed\n\n" WHITE);
      sfMusic_play(navy->tab_m[2]);
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
    atk_on_map2(atk, navy, nb);
  return (0);
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

int		pid_null(t_navy *navy, int bot)
{
  static int	i;
  int		nb;

  if (i == 0)
    {
      nb = do_atk(navy->usr2_pid, navy, bot);
      if (nb == 1 || nb == 2)
	return (nb);
      i = 1;
    }
  else
    {
      if ((end(navy->emap)) == 1)
	return (2);
      my_printf(BLUE "waiting for enemy's attack...\n" WHITE);
      nb = do_wait(navy, 2, navy->usr2_pid);
      if (nb == 1 || nb == 2)
	return (nb);
      print_map_navy(navy->map, navy->emap, navy);
      i = 0;
    }
  return (0);
}

int		pid_no_null(t_navy *navy, int bot)
{
  static int	i;
  int		nb;

  nb = 0;
  if (i == 1)
    {
      nb = do_atk(navy->usr1_pid, navy, bot);
      if (nb == 2 || nb == 1)
	return (nb);
      print_map_navy(navy->map, navy->emap, navy);
      i = 0;
    }
  else
    {
      if ((end(navy->emap)) == 1)
	return (2);
      my_printf(BLUE "waiting for enemy's attack...\n" WHITE);
      nb = do_wait(navy, 1, navy->usr1_pid);
      if (nb == 1 || nb == 2)
	return (nb);
      i = 1;
    }
  return (0);
}

int		my_process_play(t_navy *navy, pid_t pid, int bot)
{
  int		nb;

  nb = 0;
  signal(SIGUSR1, recep);
  signal(SIGUSR2, recep2);
  if (pid == 0)
    {
      nb = pid_null(navy, bot);
      if (nb == 2 || nb == 1)
	return (nb);
    }
  else if (pid != 0)
    {
      nb = pid_no_null(navy, bot);
      if (nb == 2 || nb == 1)
	return (nb);
    }
  return (0);
}
