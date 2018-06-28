/*
** print_info.c for  in /home/armin.pc/delivery/PSU_2016_navy/bonus
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Feb 10 13:19:59 2017 Enguerrand Arminjon
** Last update Sun Feb 12 19:06:22 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <ncurses.h>
#include "my.h"

void		printf_info()
{
  my_putstr("USAGE\n\t./navy [first_player_pid] navy positions [-bot]\n");
  my_putstr("DESCRIPTION\n\tFirst_player_pid:\tOnly for the 2nb player.");
  my_putstr(" PID of the first player, \n\tNavy_positions:\t\tFile represent");
  my_putstr("ing the positions of the ships.\n\tBot:\t\t\tYou can play with");
  my_putstr(" or without an IA or IA vs IA\n");
}

void		print_score_end(int col, int row, t_navy *navy)
{
  mvprintw((row/2 + 6), (col/2 - 5), "%s%i", "score : ", navy->score);
}

void		print1(int col, int row, t_navy *navy)
{
  sleep(2);
  initscr();
  curs_set(0);
  clear();
  noecho();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  refresh();
  getmaxyx(stdscr, row, col);
  attron(COLOR_PAIR(1));
  attron(A_BOLD);
  mvprintw(row/2 - 1, (col - 45)/2, "%s", "  ___   _   __  __ ___    ");
  mvprintw(row/2 - 1, (col + 8)/2, "%s", "_____   _____ ___ ");
  mvprintw(row/2, (col - 45)/2, "%s", " / __| /_\\ |  \\/  | __|  ");
  mvprintw(row/2, (col + 6)/2, "%s", "/ _ \\ \\ / / __| _ \\");
  mvprintw(row/2 + 1, (col - 45)/2, "%s", "| (_ |/ _ \\| |\\/| | _|  ");
  mvprintw(row/2 + 1, (col + 4)/2, "%s", "| (_) \\ V /| _||   /");
  mvprintw(row/2 + 2, (col - 45)/2, "%s", " \\___/_/ \\_\\_|  |_|___|  ");
  mvprintw(row/2 + 2, (col + 5)/2, "%s", " \\___/ \\_/ |___|_|_\\");
  print_score_end(col, row, navy);
  refresh();
  getch();
  sleep(1);
  endwin();
}

void		print2(int col, int row, t_navy *navy)
{
  sleep(2);
  initscr();
  curs_set(0);
  clear();
  noecho();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  refresh();
  getmaxyx(stdscr, row, col);
  attron(COLOR_PAIR(1));
  attron(A_BOLD);
  mvprintw(row/2 - 1, (col - 35)/2, "%s", "__   _____  _   _  __      ");
  mvprintw(row/2 - 1, (col + 19)/2, "%s", "_____ _  _ ");
  mvprintw(row/2, (col - 35)/2, "%s", "\\ \\ / / _ \\| | | | \\ \\    ");
  mvprintw(row/2, (col + 16)/2, "%s", "/ /_ _| \\| |");
  mvprintw(row/2 + 1, (col - 35)/2, "%s", " \\ V / (_) | |_| |  \\");
  mvprintw(row/2 + 1, (col + 9)/2, "%s", "\\/\\/ / | || .` |");
  mvprintw(row/2 + 2, (col - 35)/2, "%s", "  |_| \\___/ \\___/    ");
  mvprintw(row/2 + 2, (col + 4)/2, "%s", " \\_/\\_/ |___|_|\\_|");
  print_score_end(col, row, navy);
  refresh();
  getch();
  sleep(1);
  endwin();
}
