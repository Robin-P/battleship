/*
** tab_malloc.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Jan 30 17:42:04 2017 Enguerrand Arminjon
** Last update Wed Feb  1 10:58:23 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	**malloc_map(char **map)
{
  int	i;

  i = 0;
  if ((map = malloc(sizeof(char *) * 11)) == NULL)
    return (NULL);
  while (i < 10)
    {
      if ((map[i] = malloc(sizeof(char) * 18)) == NULL)
	return (NULL);
      map[i][0] = '\0';
      i = i + 1;
    }
  map[i] = '\0';
  return (map);
}

char	**my_map_to_tab(char **map)
{
  if ((map = malloc_map(map)) == NULL)
    return (NULL);
  map[0] = my_strcat(map[0], " |A B C D E F G H");
  map[1] = my_strcat(map[1], "-+---------------");
  map[2] = my_strcat(map[2], "1|. . . . . . . .");
  map[3] = my_strcat(map[3], "2|. . . . . . . .");
  map[4] = my_strcat(map[4], "3|. . . . . . . .");
  map[5] = my_strcat(map[5], "4|. . . . . . . .");
  map[6] = my_strcat(map[6], "5|. . . . . . . .");
  map[7] = my_strcat(map[7], "6|. . . . . . . .");
  map[8] = my_strcat(map[8], "7|. . . . . . . .");
  map[9] = my_strcat(map[9], "8|. . . . . . . .");
  map[10] = '\0';
  return (map);
}
