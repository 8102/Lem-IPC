/*
** text.c for Lemipc in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  8 17:21:49 2015 Johan Paasche
** Last update Sun Mar  8 17:30:40 2015 Johan Paasche
*/

#include "lemiPC.h"

void		text(t_gui *screen, char *message, int x, int y)
{
  SDL_Surface	*text;
  SDL_Rect	position;
  SDL_Color	color;

  position.x = x;
  position.y = y;
  color.r = 255;
  color.g = 225;
  color.b = 200;
  color.unused = 0;
  text = TTF_RenderText_Blended(screen->font, message, color);
  SDL_BlitSurface(text, NULL, screen->screen, &position);
  SDL_FreeSurface(text);
}
