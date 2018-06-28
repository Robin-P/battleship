/*
** navy.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 31 10:22:30 2017 Enguerrand Arminjon
** Last update Fri Feb 10 09:04:46 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "navy.h"
#include "global.h"

t_signal	g_signal;

int		do_atk(int pid, t_navy *navy)
{
  char		*atk_pos;

  if ((atk_pos = prompt_user(1)) == NULL)
    return (84);
  send_signal_to_process(atk_pos, pid, SIGUSR1, SIGUSR2);
  g_signal.my_sig2 = 0;
  g_signal.my_sig1 = 0;
  pause();
  if (g_signal.my_sig2 == 1)
    {
      navy->emap[atk_pos[1] - 47][(atk_pos[0] - 64) * 2] = 'x';
      my_printf("%s: hit\n\n", atk_pos);
    }
  else if (g_signal.my_sig1 == 1)
    {
      if (navy->emap[atk_pos[1] - 47][(atk_pos[0] - 64) * 2] == 'x')
	navy->emap[atk_pos[1] - 47][(atk_pos[0] - 64) * 2] = 'x';
      else
	navy->emap[atk_pos[1] - 47][(atk_pos[0] - 64) * 2] = 'o';
      my_printf("%s: missed\n\n", atk_pos);
    }
  free(atk_pos);
  return (0);
}

int		do_wait(t_navy *navy, int nb)
{
  char		recep_atk[2];

  my_putstr("waiting for enemy's attack...\n");
  g_signal.my_sig1 = 0;
  g_signal.my_sig2 = 0;
  while (g_signal.my_sig2 != 1)
    pause();
  recep_atk[0] = g_signal.my_sig1 + 64;
  g_signal.my_sig1 = 0;
  while (g_signal.my_sig2 != 2)
    pause();
  recep_atk[1] = g_signal.my_sig1 + 48;
  recep_atk[2] = '\0';
  my_printf("%s: ", recep_atk);
  atk_on_map(recep_atk, navy, nb);
  return (0);
}

int		for_win()
{
  g_signal.my_sigend = 1;
  return (1);
}

int		my_navy(t_navy *navy, pid_t pid, int nb)
{
  g_signal.my_sigend = 0;
  while (1)
    {
      nb = my_process_play(navy, pid);
      if (nb == 84 || nb == 2)
	return (nb == 2 ? 0 : nb);
      if (pid == 0)
	{
	  if (g_signal.my_sigend == 1)
	    return (0);
	  if (end(navy->map) == 1)
	    return (for_win());
	}
      else if (pid != 0)
	{
	  if (g_signal.my_sigend == 1)
	    return (0);
	  if (end(navy->map) == 1)
	    return (for_win());
	}
    }
  return (0);
}
