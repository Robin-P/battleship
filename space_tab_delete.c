/*
** space_tab_delete.c for  in /home/armin.pc/delivery/PSU_2016_navy
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Fri Feb  3 20:55:28 2017 Enguerrand Arminjon
** Last update Fri Feb  3 21:08:14 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

char	*space_tab_delete(char *str, int i, int a)
{
  char	*new;

  new = NULL;
  if (str == NULL)
    return (NULL);
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
    {
      i++;
      a++;
    }
  if ((new = malloc(sizeof(char) * (a + 1))) == NULL)
    return (NULL);
  i = 0;
  a = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
    new[a++] = str[i++];
  new[a] = '\0';
  free(str);
  return (new);
}
