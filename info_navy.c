/*
** info_navy.c for  in /home/armin.pc/delivery/PSU_2016_navy
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Fri Feb  3 10:27:58 2017 Enguerrand Arminjon
** Last update Fri Feb  3 10:29:31 2017 Enguerrand Arminjon
*/

#include "my.h"

int	end(char **map)
{
  int	i;
  int	j;
  int	k;

  i = 2;
  k = 0;
  while (map[i] != '\0')
    {
      j = 2;
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == 'x')
	    k = k + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  if (k == 14)
    return (1);
  return (0);
}

int	print_map_navy(char **map, char **emap)
{
  my_putstr("my positions:\n");
  print_tab(map);
  my_putstr("\nenemy's positions:\n");
  print_tab(emap);
  my_putchar('\n');
  return (0);
}
