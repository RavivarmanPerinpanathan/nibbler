//
// Display_Lib.hpp for display_lib in /home/perinp_r/rendu/cpp_nibbler
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:33:29 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:13:45 2015 ravivarman perinpanathan
//

#ifndef         __DISPLAY_LIB_HPP__
#define         __DISPLAY_LIB_HPP__

#include        <iostream>
#include        <string>
#include	"Default.hpp"

class           Display_Lib
{
public:
  virtual ~Display_Lib() {};

  virtual void          init_win(int x, int y) = 0;
  virtual void		read_direction(eDir * direction) = 0;
  virtual void          display_square(int x, int y) = 0;
  virtual void          delete_square(int x, int y) = 0;
  virtual void		display_food(int x, int y) = 0;
  virtual void          destroy_win() = 0;
};

#endif
