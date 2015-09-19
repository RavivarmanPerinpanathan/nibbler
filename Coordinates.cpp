//
// Coordinates.cpp for coordinates in /home/perinp_r/rendu/cpp_nibbler
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:30:44 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:13:21 2015 ravivarman perinpanathan
//

#include	<iostream>
#include	"Coordinates.hpp"

Coord::Coord(const int x, const int y) : 
  _x(x), _y(y)
{
}

Coord::Coord(const Coord & other)
{
  this->_x = other.getX();
  this->_y = other.getY();
}

Coord::~Coord(void)
{
}

Coord&		Coord::operator=(const Coord & other)
{
  this->_x = other.getX();
  this->_y = other.getY();
  return (*this);
}

Coord&		Coord::operator+(const Coord & other)
{
  Coord          *res = new Coord(this->_x + other.getX(), this->_y + other.getY());
  return (*res);
}

int		Coord::getX(void) const
{
  return (this->_x);
}

int		Coord::getY(void) const
{
  return (this->_y);
}

void		Coord::setX(int x)
{
  this->_x = x;
}

void		Coord::setY(int y)
{
  this->_y = y;
}
