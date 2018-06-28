/*
** print_tab.c for  in /home/armin.pc/delivery/PSU_2016_minishell1
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Jan 10 09:11:33 2017 Enguerrand Arminjon
** Last update Sat Feb 11 15:09:48 2017 Enguerrand Arminjon
*/

#include "my.h"

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
      if (i == 3 && nb == 0)
	my_printf(CYAN "Score : %i", navy->score);
      my_putchar('\n');
      i++;
    }
}
