/*
** recep.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Feb  3 10:50:57 2017 Enguerrand Arminjon
** Last update Fri Feb  3 10:53:06 2017 Enguerrand Arminjon
*/

#include "navy.h"
#include "global.h"

t_signal	g_signal;

void		recep()
{
  g_signal.my_sig1 = g_signal.my_sig1 + 1;
}

void		recep2()
{
  g_signal.my_sig2 = g_signal.my_sig2 + 1;
}
