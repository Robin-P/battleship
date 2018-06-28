/*
** main.c for  in /home/armin.pc/delivery/PSU_2016_navy
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Jan 30 09:03:12 2017 Enguerrand Arminjon
** Last update Sun Feb 12 18:48:44 2017 Enguerrand Arminjon
*/

#include <ncurses.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "navy.h"

void		display_end_game(t_navy *navy, int nb)
{
  int		col;
  int		row;

  col = 0;
  row = 0;
  print_map_navy(navy->map, navy->emap, navy);
  if (nb == 1)
    print1(col, row, navy);
  if (nb == 0)
    print2(col, row, navy);
  navy->map = free_tab(navy->map);
  navy->emap = free_tab(navy->emap);
  sfMusic_destroy(navy->tab_m[0]);
  sfMusic_destroy(navy->tab_m[1]);
  sfMusic_destroy(navy->tab_m[2]);
  sfMusic_destroy(navy->tab_m[3]);
  sfMusic_destroy(navy->tab_m[4]);
  sfMusic_destroy(navy->tab_m[5]);
  sfMusic_destroy(navy->tab_m[6]);
  free(navy->tab_m);
}

int		add_in_struct(t_navy *navy, pid_t pid)
{
  navy->emap = NULL;
  navy->map = NULL;
  navy->tab_m = NULL;
  navy->last_hit = 0;
  navy->score = 0;
  navy->hit = 0;
  navy->miss = 0;
  if ((navy->tab_m = malloc(sizeof(char *) * 7)) == NULL)
    return (84);
  navy->tab_m[0] = sfMusic_createFromFile("music/launch.wav");
  navy->tab_m[1] = sfMusic_createFromFile("music/hit.wav");
  navy->tab_m[2] = sfMusic_createFromFile("music/plouf.wav");
  navy->tab_m[3] = sfMusic_createFromFile("music/nukeboom.wav");
  navy->tab_m[4] = sfMusic_createFromFile("music/nuke.wav");
  navy->tab_m[5] = sfMusic_createFromFile("music/main.wav");
  navy->tab_m[6] = '\0';
  if (pid == 0)
    sfMusic_play(navy->tab_m[5]);
  system("clear");
  return (0);
}

int		my_main_navy(char *file, pid_t pid, int bot, int fd)
{
  t_navy	navy;
  int		nb;

  add_in_struct(&navy, pid);
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
      || ((print_map_navy(navy.map, navy.emap, &navy)) == 84))
    return (84);
  nb = my_navy(&navy, pid, 0, bot);
  display_end_game(&navy, nb);
  if (nb == 1)
    my_putstr("Enemy won\n");
  else if (nb == 0)
    my_putstr("I won\n");
  return (nb);
}

int		main(int ac, char **av)
{
  system("clear");
  if (ac < 2 || ac > 4)
    return (my_puterror("./navy -h\n", 2, 84));
  else if (ac == 2 && (my_strcmp(av[1], "-h")) == 0)
    printf_info();
  else
    {
      if (ac == 4 && (my_strcmp(av[3], "-bot")) == 0)
	return (my_main_navy(av[2], my_getnbr(av[1]), 1, 0));
      else if (ac == 3 && my_strcmp(av[2], "-bot") == 0)
	return (my_main_navy(av[1], 0, 1, 0));
      else if (ac == 3)
	return (my_main_navy(av[2], my_getnbr(av[1]), 0, 0));
      else if (ac == 2)
	return (my_main_navy(av[1], 0, 0, 0));
    }
  return (0);
}
