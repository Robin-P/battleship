/*
** navy.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 31 10:22:30 2017 Enguerrand Arminjon
** Last update Sun Feb 12 18:59:22 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "navy.h"
#include "global.h"

t_signal	g_signal;

int		do_atk_2(t_navy *navy, char *atk_pos)
{
  if (navy->emap[atk_pos[1] - 47][(atk_pos[0] - 64) * 2] == 'x')
    navy->emap[atk_pos[1] - 47][(atk_pos[0] - 64) * 2] = 'x';
  else
    navy->emap[atk_pos[1] - 47][(atk_pos[0] - 64) * 2] = 'o';
  my_printf("%s : ", atk_pos);
  my_putstr(CYAN "missed\n\n" WHITE);
  navy->last_hit = 0;
  navy->miss++;
  return (0);
}

int		do_atk(int pid, t_navy *navy, int bot)
{
  char		*atk_pos;

  if ((atk_pos = prompt_user(1, bot, NULL, NULL)) == NULL)
    return (84);
  if (my_strcmp(atk_pos, "/win") == 0)
    return (2);
  if ((my_strcmp(atk_pos, "/nuke") == 0) || (my_strcmp(atk_pos, "/exit")) == 0)
    return (my_main_cmds_send(navy, pid, atk_pos));
  play_my_music(navy, atk_pos, pid);
  g_signal.my_sig2 = 0;
  g_signal.my_sig1 = 0;
  pause();
  if (g_signal.my_sig2 == 1)
    {
      navy->emap[atk_pos[1] - 47][(atk_pos[0] - 64) * 2] = 'x';
      my_printf("%s : ", atk_pos);
      my_putstr(RED "hit\n\n" WHITE);
      my_score(navy);
    }
  else
    do_atk_2(navy, atk_pos);
  free(atk_pos);
  return (0);
}

int		do_wait(t_navy *navy, int nb, pid_t pid)
{
  char		recep_atk[2];

  signal(SIGINT, my_new_signal);
  g_signal.my_sig1 = 0;
  g_signal.my_sig2 = 0;
  while (g_signal.my_sig2 != 1)
    {
      if (g_signal.my_sig2 == -1)
	return (my_main_cmds_send(navy, pid, "/sigint"));
      pause();
    }
  recep_atk[0] = g_signal.my_sig1 + 64;
  g_signal.my_sig1 = 0;
  while (g_signal.my_sig2 != 2)
    pause();
  recep_atk[1] = g_signal.my_sig1 + 48;
  recep_atk[2] = '\0';
  if (my_strcmp(recep_atk, "G9") == 0 || my_strcmp(recep_atk, "H9") == 0)
    return (my_main_cmds_add(navy, recep_atk));
  else
    {
      my_printf("%s: ", recep_atk);
      atk_on_map(recep_atk, navy, nb);
    }
  return (0);
}

int		for_win()
{
  g_signal.my_sigend = 1;
  return (1);
}

int		my_navy(t_navy *navy, pid_t pid, int nb, int bot)
{
  g_signal.my_sigend = 0;
  while (1)
    {
      nb = my_process_play(navy, pid, bot);
      if (nb == 84 || nb == 2 || nb == 1)
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
