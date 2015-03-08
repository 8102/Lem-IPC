/*
** text.c for Lemipc in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  8 17:21:49 2015 Johan Paasche
** Last update Sun Mar  8 20:32:32 2015 Johan Paasche
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

void		display_team(t_gui *screen, unsigned char *map, int nb, int y)
{
  int		i;
  int		cnt;
  char		str[50];

  i = 0;
  cnt = 0;
  while (i < MAP_SIZE)
    {
      if (map[i] == nb)
	++cnt;
      ++i;
    }
  sprintf(str, "TEAM %d :  %d", nb, cnt);
  text(screen, str, CELL_SIZE * SIDE_SIZE , y);
}

void		information(t_gui *screen, unsigned char *map)
{
  int		i;
  int		y;

  i = 0;
  y = 10;
  while (i < 255)
    {
      if (screen->team_array[i] == 1)
	{
	  display_team(screen, map, i, y);
	  y += 50;
	}
      ++i;
    }
}
