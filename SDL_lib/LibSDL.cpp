//
// LibSDL.cpp for LibSDL in /home/perinp_r/rendu/cpp_nibbler/SDLDisplayLib
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:52:23 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:15:20 2015 ravivarman perinpanathan
//

#include	<unistd.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_keyboard.h>
#include	"../Default.hpp"
#include	"LibSDL.hpp"

LibSDL::LibSDL()
{
}

LibSDL::~LibSDL()
{
}

void		LibSDL::init_win(int x, int y)
{
  SDL_Init(SDL_INIT_VIDEO);
  this->background = SDL_LoadBMP("SDLDisplayLib/images/background.bmp");
  this->snakepart = SDL_LoadBMP("SDLDisplayLib/images/snakepart.bmp");
  this->foodpart = SDL_LoadBMP("SDLDisplayLib/images/foodpart.bmp");
  this->screen = SDL_SetVideoMode(x * SQUARE_SIZE, y * SQUARE_SIZE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_FillRect(this->screen, NULL, SDL_MapRGB(this->screen->format, 66, 255, 0));
  SDL_WM_SetCaption("Un super Nibbler", NULL);
  this->size_x = x * SQUARE_SIZE ;
  this->size_y = y * SQUARE_SIZE;
}

void		LibSDL::display_square(int x, int y)
{
  SDL_Rect	pos;

  pos.x = x * SQUARE_SIZE;
  pos.y = y * SQUARE_SIZE;
  SDL_BlitSurface(this->snakepart, NULL, this->screen, &pos);
  SDL_Flip(this->screen);
}

void            LibSDL::display_food(int x, int y)
{
  SDL_Rect      pos;

  pos.x = x * SQUARE_SIZE;
  pos.y = y * SQUARE_SIZE;
  SDL_BlitSurface(this->foodpart, NULL, this->screen, &pos);
  SDL_Flip(this->screen);
}

void		LibSDL::delete_square(int x, int y)
{
  SDL_Rect	pos;

  pos.x = x * SQUARE_SIZE;
  pos.y = y * SQUARE_SIZE;
  SDL_BlitSurface(this->background, NULL, this->screen, &pos);
  SDL_Flip(this->screen);
}

void		LibSDL::destroy_win()
{
}

void		LibSDL::read_direction(eDir* dir)
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return;
    case SDL_MOUSEMOTION:
      {
	write(1, "m", 1);
      }
    case SDL_KEYDOWN:
      {
	if (event.key.keysym.sym == SDLK_DOWN && *dir != UP)
	  *dir = DOWN;
	if (event.key.keysym.sym == SDLK_LEFT && *dir != RIGHT)
	  *dir = LEFT;
	if (event.key.keysym.sym == SDLK_RIGHT && *dir != LEFT)
	  *dir = RIGHT;
	if (event.key.keysym.sym == SDLK_UP && *dir != DOWN)
	  *dir = UP;
      }
    }
}

extern "C"
{
  Display_Lib*   create_Lib(void)
  {
    return (new LibSDL);
  }
}
