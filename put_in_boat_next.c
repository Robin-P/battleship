/*
** put_in_boat_next.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Feb  3 10:44:25 2017 Enguerrand Arminjon
** Last update Fri Feb  3 10:45:03 2017 Enguerrand Arminjon
*/

#include "my.h"

char	**put_boat_vert(char **map, char *s)
{
  int	i;

  i = 0;
  if (s[3] < s[6])
    {
      while (i < my_getnbr(s))
	{
	  map[s[3] - 47 + i][(s[2] - 64) * 2] = s[0];
	  i++;
	}
      i = 0;
    }
  else
    {
      while (i < my_getnbr(s))
	{
	  map[s[6] - 47 + i][(s[2] - 64) * 2] = s[0];
	  i++;
	}
      i = 0;
    }
  return (map);
}
