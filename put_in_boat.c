/*
** put_in_boat.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Jan 30 17:43:18 2017 Enguerrand Arminjon
** Last update Fri Feb  3 10:44:41 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char		**put_boat_hort(char **map, char *s)
{
  int		i;

  i = 0;
  if (s[2] < s[5])
    {
      while (i < my_getnbr(s))
	{
	  map[s[3] - 47][(s[2] - 64 + i) * 2] = s[0];
	  i++;
	}
      i = 0;
    }
  else
    {
      while (i < my_getnbr(s))
	{
	  map[s[6] - 47][(s[2] - 64 - i) * 2] = s[0];
	  i++;
	}
      i = 0;
    }
  return (map);
}

char		*swap_my_pos(char *s)
{
  char		x;

  s = my_strupper(s);
  if ((s[2] >= '1' && s[2] <= '8') && (s[3] >= 'A' && s[3] <= 'H'))
    {
      x = s[2];
      s[2] = s[3];
      s[3] = x;
    }
  if ((s[5] >= '1' && s[5] <= '8') && (s[6] >= 'A' && s[6] <= 'H'))
    {
      x= s[5];
      s[5] = s[6];
      s[6] = x;
    }
  return (s);
}

char		*check_my_boat(char *s)
{
  static int	a = 0;
  static int	b = 0;
  static int	c = 0;
  static int	d = 0;

  if ((my_strlen(s) != 7) || (s[0] < '0' || s[0] > '9')
      || (((s = swap_my_pos(s)) == NULL))
      || ((s[2] == s[5] && s[3] == s[6]) || (s[2] != s[5] && s[3] != s[6]))
      || ((s[0] != (s[3] - s[6] + '1') && (s[0] != (s[6] - s[3] + '1'))
	   && s[0] != (s[2] - s[5] + '1') && (s[0] != (s[5] - s[2] + '1')))))
    return (NULL);
  if (s[0] == '2')
    a = a + 1;
  else if (s[0] == '3')
    b = b + 1;
  else if (s[0] == '4')
    c = c + 1;
  else if (s[0] == '5')
    d = d + 1;
  if (a > 1 || b > 1 || c > 1 || d > 1)
    return (NULL);
  return (s);
}

int		lap_boat(char **map, int a, int b, int c)
{
  int		i;
  int		j;
  int		d;

  d = 0;
  i = 1;
  while (map[++i] != '\0')
    {
      j = 2;
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == '2')
	    a = a + 1;
	  if (map[i][j] == '3')
	    b = b + 1;
	  if (map[i][j] == '4')
	    c = c + 1;
	  if (map[i][j] == '5')
	    d = d + 1;
	  j = j + 1;
	}
    }
  if ((a != 2) || (b != 3) || (c != 4) || (d != 5))
    return (1);
  return (0);
}

char		**put_boat(char **map, int fd)
{
  char		*s;
  int		i;

  i = 0;
  while ((s = get_next_line(fd)))
    {
      i = 1;
      if ((check_my_boat(s)) == NULL)
	return (NULL);
      if (s[2] == s[5])
	map = put_boat_vert(map, s);
      else
	map = put_boat_hort(map, s);
      free(s);
    }
  if (lap_boat(map, 0, 0, 0) == 1)
    return (NULL);
  return (i == 0 ? NULL : map);
}
