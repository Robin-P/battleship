/*
** dual_process.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Wed Feb  1 09:26:55 2017 Enguerrand Arminjon
** Last update Fri Feb  3 14:11:26 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <signal.h>
#include "my.h"
#include "navy.h"

int			stock_pid(int nb)
{
  static int		pid;

  if (nb != -1)
    pid = nb;
  return (pid);
}

void			my_signal(int sig, siginfo_t *info, void *context)
{
  sig = sig;
  context = context;
  my_putstr("enemy connected\n\n");
  stock_pid(info->si_pid);
}

void			my_signal2(int sig, siginfo_t *info, void *context)
{
  sig = sig;
  context = context;
  info = info;
  my_putstr("successfully connected\n\n");
}

int			dual_process_next(pid_t pid, struct sigaction siga)
{
  usleep(5000);
  if ((kill(pid, SIGUSR2)) == -1)
    return (84);
  siga.sa_flags = SA_SIGINFO;
  siga.sa_sigaction = &my_signal2;
  sigemptyset(&siga.sa_mask);
  sigaction(SIGUSR1, &siga, NULL);
  pause();
  return (0);
}

int			dual_process(t_navy *navy, pid_t pid)
{
  struct sigaction	siga;

  my_printf("my_pid: %i\n", getpid());
  if (pid == 0)
    {
      my_putstr("waiting for enemy connexion...\n");
      siga.sa_flags = SA_SIGINFO;
      siga.sa_sigaction = &my_signal;
      sigemptyset(&siga.sa_mask);
      sigaction(SIGUSR2, &siga, NULL);
      pause();
      navy->usr2_pid = stock_pid(-1);
      usleep(5000);
      kill(stock_pid(-1), SIGUSR1);
    }
  else if (pid != 0)
    return (dual_process_next(pid, siga));
  return (0);
}
