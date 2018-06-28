/*
** my_score.c for  in /home/armin.pc/delivery/PSU_2016_navy/bonus
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Sat Feb 11 15:11:38 2017 Enguerrand Arminjon
** Last update Sat Feb 11 15:28:43 2017 Enguerrand Arminjon
*/

#include "my.h"
#include "navy.h"

void		my_score(t_navy *navy)
{
  static int	last;
  static int	multi = 2;

  if (last == 1)
    {
      navy->score = navy->score + (100 * multi);
      multi++;
    }
  else
    {
      navy->score = navy->score + 100;
      multi = 2;
    }
  last = 1;
  navy->hit++;
}
