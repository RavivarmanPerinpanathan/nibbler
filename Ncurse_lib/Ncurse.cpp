//
// Ncurse.cpp for Ncurse in /home/perinp_r/rendu/cpp_nibbler/NcurseDisplayLib
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:53:25 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:15:04 2015 ravivarman perinpanathan
//

#include	<stdio.h>
#include	<pthread.h>
#include	<curses.h>
#include	<term.h>
#include	<string.h>
#include	<iostream>
#include	"../Default.hpp"
#include	"Ncurse.hpp"

LibNcurse::LibNcurse()
{
}

LibNcurse::~LibNcurse()
{
}

void            LibNcurse::init_win(int x, int y)
{
  char			*clear;
  char			*curs_off;
  struct termios	term;

  if (tgetent(NULL, "xterm") == -1 || tcgetattr(0, &term) == -1)
    {
      std::cerr << "Error initialazing termcaps variables." << std::endl;
      return ;
    }
  term.c_lflag &= ~(ICANON | ECHO);
  if (tcsetattr(0, 0, &term) == -1 || tgetent(NULL, "xterm") == -1)
    {
      std::cerr << "Error initialazing termcaps variables." << std::endl;
      return ;
    }
  clear = tgetstr("cl", NULL);
  write(1, clear, strlen(clear));
  curs_off = tgetstr("vi", NULL);
  write(1, curs_off, strlen(curs_off));
  this->display_board(x, y);
}

void		LibNcurse::display_board(int x, int y)
{
  char		*pos;
  int		x2 = 1;
  int		y2 = 1;

  pos = tgoto(tgetstr("cm", NULL), 0, 0);
  write(1, pos, strlen(pos));
  write(1, "o", 1);
  while (x2 < x + 1)
    {
      write(1, "-", 1);
      x2++;
    }
  write(1, "o", 1);
  pos = tgoto(tgetstr("cm", NULL), 0, y + 1);
  write(1, pos, strlen(pos));
  write(1, "o", 1);
  x2 = 1;
  while (x2 < x + 1)
    {
      write(1, "-", 1);
      x2++;
    }
  write(1, "o", 1);
  while (y2 < y + 1)
    {
      pos = tgoto(tgetstr("cm", NULL), 0, y2);
      write(1, pos, strlen(pos));
      write(1, "|", 1);
      pos = tgoto(tgetstr("cm", NULL), x + 1, y2);
      write(1, pos, strlen(pos));
      write(1, "|", 1);
      y2++;
    }
}

void            LibNcurse::display_square(int x, int y)
{
  char		*str_pos;

  str_pos = tgoto(tgetstr("cm", NULL), x + 1, y + 1);
  write(1, str_pos, strlen(str_pos));
  write(1, "O", 1);
}

void            LibNcurse::display_food(int x, int y)
{
  char          *str_pos;

  str_pos = tgoto(tgetstr("cm", NULL), x + 1, y + 1);
  write(1, str_pos, strlen(str_pos));
  write(1, "x", 1);
}

void            LibNcurse::delete_square(int x, int y)
{
  char          *str_pos;

  str_pos = tgoto(tgetstr("cm", NULL), x + 1, y + 1);
  write(1, str_pos, strlen(str_pos));
  write(1, " ", 1);
}

void            LibNcurse::destroy_win()
{
  char		*cl;
  char		*curs_on;

  write(1, "salut\n", 6);
  cl = tgetstr("cl", NULL);
  write(1, cl, strlen(cl));
  curs_on = tgetstr("ve", NULL);
  write(1, curs_on, strlen(curs_on));
  printf("GAME OVER !!\n");
}

int		str_key_cmp(char *input, char key)
{
  if (input && input[0] && input[0] == 0x1B)
    {
      if (input[0] && input[0] == 27 && input[1] && input[1] == '['
	  && input[2] && input[2] == key)
	return (0);
      else
	  return (-1);
    }
  else
    return (-1);
}

void		*thread_key(void *dir2)
{
  char          buff[4];
  eDir		*dir;

  dir = (eDir*)dir2;
  if (read(0, buff, 4) == -1)
    return (NULL);
  if (str_key_cmp(buff, 'A') == 0 && *dir != DOWN)
    *dir = UP;
  else if (str_key_cmp(buff, 'B') == 0 && *dir != UP)
    *dir = DOWN;
  else if (str_key_cmp(buff, 'C') == 0 && *dir != LEFT)
    *dir = RIGHT;
  else if (str_key_cmp(buff, 'D') == 0 && *dir != RIGHT)
    *dir = LEFT;
  return (NULL);
}

void            LibNcurse::read_direction(eDir* dir)
{
  pthread_t	th;

  pthread_create(&th, NULL, thread_key, (void*)dir);
}

extern "C"
{
  Display_Lib*   create_Lib(void)
  {
    return (new LibNcurse);
  }
}
