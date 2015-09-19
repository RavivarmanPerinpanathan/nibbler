//
// Nibbler.cpp for Nibbler in /home/perinp_r/rendu/cpp_nibbler
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:35:56 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:14:05 2015 ravivarman perinpanathan
//

#include        <string>
#include        <iostream>
#include        <list>
#include        <stdlib.h>
#include        <time.h>
#include        <dlfcn.h>
#include	<map>
#include	<list>
#include	"Default.hpp"
#include        "Nibbler.hpp"

Nibbler::Nibbler(const Coord & dimention, Display_Lib * ptr_lib) :
  _dimention(dimention), _ptr_lib(ptr_lib)
{
  this->_direction_tab[UP] = Coord(0, -1);
  this->_direction_tab[DOWN] = Coord(0, 1);
  this->_direction_tab[RIGHT] = Coord(1, 0);
  this->_direction_tab[LEFT] = Coord(-1, 0);
  this->_direction = RIGHT;
  this->_snaque.push_back(Coord(dimention.getX() / 2, dimention.getY() / 2));
  this->_snaque.push_back(Coord(dimention.getX() / 2 - 1, dimention.getY() / 2));
  this->_snaque.push_back(Coord(dimention.getX() / 2 - 2, dimention.getY() / 2));
  this->_snaque.push_back(Coord(dimention.getX() / 2 - 3, dimention.getY() / 2));
  for (std::list<Coord>::iterator it = this->_snaque.begin(); it != this->_snaque.end(); it++)
    this->_ptr_lib->display_square(it->getX(), it->getY());
  this->end = 0;
  this->_food = Coord(0, 0);
  this->new_food();
}

Nibbler::~Nibbler(void)
{
}

int             Nibbler::move_snaque(void)
{
  Coord		new_head(*(this->_snaque.begin()) + this->_direction_tab[this->_direction]);

  if (this->end == 0)
    {
      this->_ptr_lib->delete_square((this->_snaque.back()).getX(), (this->_snaque.back()).getY()); 
      this->_snaque.pop_back();
     }
  this->end = 0;
  if (this->check_square_is_valid(new_head, 0) == 0)
      return (0);
  this->_snaque.push_front(new_head);
  this->_ptr_lib->display_square((this->_snaque.begin())->getX(), (this->_snaque.begin())->getY());
  return (1);
}

int            Nibbler::set_direction(eDir & direction)
{
  if (direction == ESCAP)
    return (0);
  else if ((this->_direction == UP && direction == DOWN) ||	\
      (this->_direction == DOWN && direction == UP) ||		\
      (this->_direction == LEFT && direction == RIGHT) ||	\
      (this->_direction == RIGHT && direction == LEFT))
    return (1);
  this->_direction = direction;
  return (1);
}
void            Nibbler::new_food(void)
{  
  srand(time(NULL));
  Coord          new_food(rand() % (this->_dimention.getX() - 4) + 2, \
                         rand() % (this->_dimention.getY() - 4) + 2);
  this->_ptr_lib->delete_square(this->_food.getX(), this->_food.getY());
  if (check_square_is_valid(new_food, 1) == 0 || 
      (new_food.getX() == this->_food.getX() && new_food.getY() == this->_food.getY()))
    {
      new_food.setX(3);
      new_food.setY(3);
    }
  this->_food = new_food;
  this->_ptr_lib->display_food(this->_food.getX(), this->_food.getY());
}

int             Nibbler::check_square_is_valid(const Coord & element, int option)
{
  if (this->_food.getX() == element.getX() &&
      this->_food.getY() == element.getY() && option == 1)
    return (0);
  if (this->_food.getX() == element.getX() &&
      this->_food.getY() == element.getY())
    {
      this->new_food();
      this->end = 1;
    }
  if (element.getX() < 0 || element.getY() < 0 || 
      element.getX() >= this->_dimention.getX() ||
      element.getY() >= this->_dimention.getY())
    return (0);
  for (std::list<Coord>::iterator it = this->_snaque.begin(); it != this->_snaque.end(); it++)
    {
      if (it->getX() == element.getX() &&
	  it->getY() == element.getY())
	return (0);
    }
  return (1);
}
