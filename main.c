/*
** main.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Jan 30 09:03:12 2017 Enguerrand Arminjon
** Last update Sun Feb  5 09:20:18 2017 Enguerrand Arminjon
*/

#include <ncurses.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

void		printf_info()
{
  my_putstr("USAGE\n\t./navy [first_player_pid] navy positions\n");
  my_putstr("DESCRIPTION\n\tfirst_player_pid\tonly for the 2nb player.");
  my_putstr("  pid of the first player, \n\tnavy_positions\t\tfile represent");
  my_putstr("ing the positions of the ships.\n");
}

void		display_end_game(t_navy *navy, int nb)
{
  print_map_navy(navy->map, navy->emap);
  if (nb == 1)
    my_putstr("Enemy won\n");
  if (nb == 0)
    my_putstr("I won\n");
}

int		my_main_navy(char *file, pid_t pid)
{
  t_navy	navy;
  int		fd;
  int		nb;

  navy.map = NULL;
  navy.emap = NULL;
  if (pid != 0)
    {
      navy.usr1_pid = pid;
      navy.usr2_pid = getpid();
    }
  else
    navy.usr1_pid = getpid();
  fd = open(file, O_RDONLY);
  if ((fd == -1) || ((navy.map = my_map_to_tab(navy.map)) == NULL)
      || ((navy.map = put_boat(navy.map, fd)) == NULL)
      || ((navy.emap = my_map_to_tab(navy.emap)) == NULL)
      || ((dual_process(&navy, pid)) == 84)
      || ((print_map_navy(navy.map, navy.emap)) == 84))
    return (84);
  nb = my_navy(&navy, pid, 0);
  display_end_game(&navy, nb);
  navy.map = free_tab(navy.map);
  navy.emap = free_tab(navy.emap);
  return (nb);
}

int		main(int ac, char **av)
{
  if (ac < 2 || ac > 3)
    return (my_puterror("./navy -h\n", 2, 84));
  else if (ac == 2 && (my_strcmp(av[1], "-h")) == 0)
    printf_info();
  else
    {
      if (ac == 3)
	return (my_main_navy(av[2], my_getnbr(av[1])));
      else
	return (my_main_navy(av[1], 0));
    }
  return (0);
}
