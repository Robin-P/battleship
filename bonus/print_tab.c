/*
** print_tab.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 10 09:11:33 2017 Enguerrand Arminjon
** Last update Mon Feb 13 09:18:02 2017 Enguerrand Arminjon
*/

#include "my.h"

void	print_stat(t_navy *navy, int i)
{
  if (i == 3)
    my_printf(GREEN "\t\t -------------------------" WHITE);
  if (i == 4)
    {
      my_putstr(GREEN "\t\t| Score : ");
      my_printf(YELLOW "\t   %i" WHITE, navy->score);
    }
  if (i == 5)
    {
      my_putstr(GREEN "\t\t| Number of hits : ");
      my_printf(RED "%i / 14" WHITE, navy->hit);
    }
  if (i == 6)
    {
      my_putstr(GREEN "\t\t| Number of miss : ");
      my_printf(CYAN "%i" WHITE, navy->miss);
    }
  if (i == 7)
    my_printf(GREEN "\t\t -------------------------" WHITE);
}

void	print_tab(char **tab, t_navy *navy, int nb)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] != '\0')
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == 'x')
	    my_printf(RED "%c" WHITE, tab[i][j]);
	  else if (tab[i][j] == 'o')
	    my_printf(CYAN "%c" WHITE, tab[i][j]);
	  else if (tab[i][j] == '-' || tab[i][j] == '+' || tab[i][j] == '|')
	    my_printf(GREEN "%c" WHITE, tab[i][j]);
	  else
	    my_putchar(tab[i][j]);
	  j++;
	}
      if (nb == 0)
	print_stat(navy, i);
      my_putchar('\n');
      i++;
    }
}
