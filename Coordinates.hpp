//
// Coordinates.hpp for coordinates in /home/perinp_r/rendu/cpp_nibbler
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:31:18 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:13:31 2015 ravivarman perinpanathan
//

#ifndef		__COORDINATES_HPP__
#define		__COORDINATES_HPP__

#include	<iostream>
#include	<string>
#include	"Default.hpp"

class		Coord
{
private:
  int		_x;
  int		_y;

public:
  Coord() {};
  Coord(const int x, const int y);
  Coord(const Coord & other);
  ~Coord();

  Coord&		operator=(const Coord & other);
  Coord&		operator+(const Coord & other);
  int		getX() const;
  int		getY() const;
  void		setX(int x);
  void		setY(int y);
};

#endif
