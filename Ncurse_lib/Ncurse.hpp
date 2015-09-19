//
// Ncurse.hpp for Ncurse in /home/perinp_r/rendu/cpp_nibbler/NcurseDisplayLib
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:53:57 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:15:00 2015 ravivarman perinpanathan
//

#ifndef		__NCURSE_HPP__
#define		__NCURSE_HPP__

#include	<sys/types.h>
#include	<unistd.h>
#include	"../Display_Lib.hpp"
#include	"../Default.hpp"

class		LibNcurse : public Display_Lib
{
private:
  int		size_x;
  int		size_y;
  void		display_board(int, int);

public:
  LibNcurse();
  ~LibNcurse();

  void		init_win(int, int);
  void		display_square(int, int);
  void		delete_square(int, int);
  void		destroy_win();
  void		display_food(int x, int y);
  void		read_direction(eDir*);
};

extern "C"
{
  Display_Lib*	create_Lib(void);
}

int		str_key_cmp(char*, char);
void		*thread_key(void*);

#endif
