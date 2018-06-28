/*
** prompt.c for  in /home/armin.pc/delivery/PSU_2016_navy
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Feb  2 15:24:59 2017 Enguerrand Arminjon
** Last update Sun Feb  5 16:03:37 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*swap_my_prompt(char *s)
{
  char	x;

  s = my_strupper(s);
  if ((s[0] >= '1' && s[0] <= '8') && (s[1] >= 'A' && s[1] <= 'H'))
    {
      x = s[0];
      s[0] = s[1];
      s[1] = x;
    }
  return (s);
}

char	*prompt_user(int i)
{
  char	*s;

  s = NULL;
  while (i == 1)
    {
      if (s != NULL)
	free(s);
      my_putstr("attack: ");
      s = space_tab_delete(get_next_line(0), 0, 0);
      my_printf("%s\n", s);
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
