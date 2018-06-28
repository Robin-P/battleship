/*
** my_strupper.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Feb  2 11:06:22 2017 Enguerrand Arminjon
** Last update Thu Feb  2 11:07:25 2017 Enguerrand Arminjon
*/

char	*my_strupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
