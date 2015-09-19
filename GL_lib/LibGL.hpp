//
// LibGL.hpp for LibGL in /home/perinp_r/rendu/cpp_nibbler
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:57:22 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:14:42 2015 ravivarman perinpanathan
//

#ifndef		__LIBGL_HPP__
#define		__LIBGL_HPP__

#include	<SDL/SDL.h>
#include	"../Display_Lib.hpp"
#include	"../Default.hpp"

class		LibGL : public Display_Lib
{
private:
  int		size_x;
  int		size_y;
  SDL_Surface	*screen;

public:
  LibGL();
  ~LibGL();

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
#endif
