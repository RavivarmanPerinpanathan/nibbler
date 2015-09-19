//
// LibGL.cpp for LibGL in /home/perinp_r/rendu/cpp_nibbler
// 
// Made by ravivarman perinpanathan
// Login   <perinp_r@epitech.net>
// 
// Started on  Sun Apr  5 20:56:28 2015 ravivarman perinpanathan
// Last update Sun Apr  5 21:14:34 2015 ravivarman perinpanathan
//

#include	<SDL/SDL.h>
#include	<SDL/SDL_keyboard.h>
#include	<GL/gl.h>
#include	<GL/glu.h>
#include	"../Default.hpp"
#include	"LibGL.hpp"

LibGL::LibGL()
{
}

LibGL::~LibGL()
{
}

void		LibGL::init_win(int x, int y)
{
  SDL_Init(SDL_INIT_VIDEO);
  this->screen = SDL_SetVideoMode(x * SQUARE_SIZE, y * SQUARE_SIZE, 32, SDL_OPENGL);
  SDL_FillRect(this->screen, NULL, SDL_MapRGB(this->screen->format, 66, 255, 0));
  SDL_WM_SetCaption("Un super Nibbler", NULL);
  this->size_x = x;
  this->size_y = y;

  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective(70,(double)640/480,1,1000);
  
  if (x >= y)
    gluLookAt(x, x , 0, 0, x/2, y/2,0,0,1);
  else
    gluLookAt(y, 0 , y ,0, x/2, y/2,0,0,1);
  glBegin(GL_QUADS);

  glColor3f(0, 0, 0xff);
  glVertex3f(0, 0, y);
  glVertex3f(0, x, y);
  glVertex3f(0, x, 0);
  glVertex3f(0, 0, 0);

  glEnd();

  glFlush();
  SDL_GL_SwapBuffers();
}

void		LibGL::display_square(int x, int y)
{
  glBegin(GL_QUADS);

  glColor3f(0, 1.0f, 0.0f);
  glVertex3f(0, x, y + 1);
  glVertex3f(0, x + 1, y + 1);
  glVertex3f(0, x + 1, y);
  glVertex3f(0, x, y);

  glEnd();

  glFlush();
  SDL_GL_SwapBuffers();  
}

void            LibGL::display_food(int x, int y)
{
  glBegin(GL_QUADS);

  glColor3f(0xff, 0, 0);
  glVertex3f(0, x, y + 1);
  glVertex3f(0, x + 1, y + 1);
  glVertex3f(0, x + 1, y);
  glVertex3f(0, x, y);

  glEnd();

  glFlush();
  SDL_GL_SwapBuffers();
}

void		LibGL::delete_square(int x, int y)
{
  glBegin(GL_QUADS);

  glColor3f(0, 0, 0xff);
  glVertex3f(0, x, y + 1);
  glVertex3f(0, x + 1, y + 1);
  glVertex3f(0, x + 1, y);
  glVertex3f(0, x, y);

  glEnd();

  glFlush();
  SDL_GL_SwapBuffers();
}

void		LibGL::destroy_win()
{
}

void		LibGL::read_direction(eDir* dir)
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return;
    case SDL_KEYDOWN:
      {
	if (event.key.keysym.sym == SDLK_UP && *dir != UP)
	  *dir = DOWN;
	if (event.key.keysym.sym == SDLK_LEFT && *dir != RIGHT)
	  *dir = LEFT;
	if (event.key.keysym.sym == SDLK_RIGHT && *dir != LEFT)
	  *dir = RIGHT;
	if (event.key.keysym.sym == SDLK_DOWN && *dir != DOWN)
	  *dir = UP;
      }
    }
}

extern "C"
{
  Display_Lib*   create_Lib(void)
  {
    return (new LibGL);
  }
}
