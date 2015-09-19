//
// LibSDL.hpp for LibSDL in /home/perinp_r/rendu/cpp_nibbler/SDLDisplayLib
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:52:41 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:15:17 2015 ravivarman perinpanathan
//

#ifndef		__SDL_HPP__
#define		__SDL_HPP__

#include	"../Display_Lib.hpp"
#include	"../Default.hpp"

class		LibSDL : public Display_Lib
{
private:
  int		size_x;
  int		size_y;
  SDL_Surface	*background;
  SDL_Surface	*snakepart;
  SDL_Surface   *foodpart;
  SDL_Surface	*screen;

public:
  LibSDL();
  ~LibSDL();

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
