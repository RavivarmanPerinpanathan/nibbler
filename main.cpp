//
// main.cpp for main in /home/perinp_r/rendu/cpp_nibbler
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:34:32 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:13:51 2015 ravivarman perinpanathan
//

#include	<unistd.h>
#include	<iostream>
#include	<dlfcn.h>
#include	<stdlib.h>
#include	"Default.hpp"
#include        "Display_Lib.hpp"
#include	"Nibbler.hpp"
#include	"Coordinates.hpp"

int			nibbler(Display_Lib *displayLib, const Coord & dimention)
{
  Nibbler		game_nibbler(dimention, displayLib);
  eDir			direction = RIGHT;

  while (42)
    {
      displayLib->read_direction(&direction);
      if (game_nibbler.set_direction(direction) == 0)
	return (0);
      if (game_nibbler.move_snaque() == 0)
	return (0);
      usleep(50000);
    }
  return (0);
}

int			main(int ac, char **av)
{
  int			high;
  int			lenght;

  if (ac == 4)
    {
      void		*dlhandle;
      if ((high = atoi(av[1])) < 10 || high > 100 || (lenght = atoi(av[2])) < 10 || lenght > 100)
	{
	  std::cerr << "Usage : ./nibbler [hight] [length] <libXXXX.so>" << std::endl
		    << " 10 < [hight|lenght] < 100" << std::endl;
	  return (-1);
	}
      const Coord       	dimention(atoi(av[1]), atoi(av[2]));
      if ((dlhandle = dlopen(av[3], RTLD_LAZY | RTLD_GLOBAL)) == NULL)
	{
	  std::cerr << dlerror() << std::endl;
	  return (0);
	}
      Display_Lib*        (*external_creator)();
      external_creator = reinterpret_cast<Display_Lib* (*)()>(dlsym(dlhandle, "create_Lib"));

      if (external_creator == NULL)
	{
	  std::cerr << "la fonction create_Lib n'a pu etre trouver dans la librairie" << std::endl;
	  return (0);
	  }
      Display_Lib	*displayLib = external_creator();
      displayLib->init_win(dimention.getX(), dimention.getY());
      nibbler(displayLib, dimention);
      displayLib->destroy_win();
      dlclose(dlhandle);
    }
  else
    std::cerr << "Usage : ./nibbler [hight] [length] <libXXXX.so>" << std::endl;
  return (0);
}
