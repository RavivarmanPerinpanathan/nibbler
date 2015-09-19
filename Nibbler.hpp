//
// Nibbler.hpp for Nibbler in /home/perinp_r/rendu/cpp_nibbler
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:37:30 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:14:19 2015 ravivarman perinpanathan
//

#ifndef         __MAP_HPP__
#define         __MAP_HPP__

#include        <string>
#include        <iostream>
#include        <dlfcn.h>
#include        <map>
#include        <list>
#include	"Default.hpp"
#include        "Display_Lib.hpp"
#include        "Coordinates.hpp"

class           Nibbler
{
private:
  Coord			_food;
  eDir                  _direction;
  std::map<eDir, Coord>	_direction_tab;
  const Coord		_dimention;
  std::list<Coord>	_snaque;
  Display_Lib     	*_ptr_lib;
  int			end;

  int                   add_square_to_snaque();
  void                  new_food();
  int                   check_square_is_valid(const Coord & element, int option);
public:
  Nibbler(const Coord & dimention, Display_Lib * ptr_lib);
  ~Nibbler();
  int			move_snaque();
  int	                set_direction(eDir & direction);
};

#endif
