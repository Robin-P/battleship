/*
** prompt.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Feb  2 15:24:59 2017 Enguerrand Arminjon
** Last update Mon Feb 13 09:16:05 2017 Enguerrand Arminjon
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "global.h"

char		*swap_my_prompt(char *s)
{
  char		x;

  s = my_strupper(s);
  if ((s[0] >= '1' && s[0] <= '8') && (s[1] >= 'A' && s[1] <= 'H'))
    {
      x = s[0];
      s[0] = s[1];
      s[1] = x;
    }
  return (s);
}

int		my_random(int min, int max)
{
  static int	rand_is_seeded = 0;

  if (rand_is_seeded == 0)
    {
      srand(time(NULL));
      rand_is_seeded = 1;
    }
  return (rand() % (max - min + 1) + min);
}

char		*my_bot()
{
  char		*s;
  char		l;
  char		n;

  if ((s = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  l = (my_random(1, 8) + 64);
  n = (my_random(1, 8) + 48);
  s[0] = l;
  s[1] = n;
  s[2] = '\0';
  return (s);
}

char		*prompt_user_next(char *s)
{
  if (g_signal.my_sig1 == -1)
    {
      free(s);
      return ("/win");
    }
  else if (s != NULL && my_strcmp(s, "/nuke") == 0)
    {
      free(s);
      return ("/nuke");
    }
  else if (s != NULL && my_strcmp(s, "/exit") == 0)
    {
      free(s);
      return ("/exit");
    }
  return (NULL);
}

char		*prompt_user(int i, int bot, char *s, char *ret)
{
  signal(SIGUSR1, my_recep_sig);
  if (bot == 1)
    return (my_bot());
  while (i == 1)
    {
      if (s != NULL)
	free(s);
      my_printf(RED_1 "attack: " WHITE);
      s = space_tab_delete(get_next_line(0), 0, 0);
      my_printf("%s\n", s);
      if ((ret = prompt_user_next(s)) != NULL)
	return (ret);
      if (s != NULL)
	{
	  swap_my_prompt(s);
	  if ((my_strlen(s) != 2) || (s[0] < 'A')
	      || (s[0] > 'H') || (s[1] < '1') || (s[1] > '8'))
	    my_putstr("wrong position\n");
	  else
	    i = 0;
	}
      else
	my_putstr("wrong position\n");
    }
  return (s);
}
