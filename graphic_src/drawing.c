/*
** drawing.c for LemIPC in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Mon Mar  2 01:12:37 2015 Johan Paasche
** Last update Sun Mar  8 20:51:51 2015 Johan Paasche
*/

#include	"lemiPC.h"

void		lighting_circle(t_gui *screen, int i)
{
  SDL_Rect	pos;
  SDL_Rect	po;
  unsigned int	color;

  color =  0x00DD8228;
  pos.x = (SIDE_SIZE * CELL_SIZE) / 2 - i % (SIDE_SIZE * CELL_SIZE / 2);
  pos.h = (pos.x + 2 * (i % (SIDE_SIZE * CELL_SIZE)));
  pos.y = (SIDE_SIZE * CELL_SIZE) / 2 - i % (SIDE_SIZE * CELL_SIZE / 2);
  pos.w = (pos.x + 2 * (i % (SIDE_SIZE * CELL_SIZE)));
  SDL_FillRect(screen->screen, &pos, color);
  po.x = (SIDE_SIZE * CELL_SIZE) / 2 - i % (SIDE_SIZE * CELL_SIZE / 2) + 20;
  po.h = (pos.x + 2 * (i % (SIDE_SIZE * CELL_SIZE))) - 20;
  po.y = (SIDE_SIZE * CELL_SIZE) / 2 - i % (SIDE_SIZE * CELL_SIZE / 2) - 20;
  po.w = (pos.x + 2 * (i % (SIDE_SIZE * CELL_SIZE))) - 20;
  SDL_FillRect(screen->screen, &po, color);
}

void		shaded_grid(t_gui *screen, int y)
{
  SDL_Rect	pos;
  int		i;
  unsigned int	color;

  i = 0;
  color =  0x00DD8228;
  screen->position.x = 0;
  screen->position.y = 0;
  screen->position.h = SIDE_SIZE * CELL_SIZE;
  screen->position.w = SIDE_SIZE * CELL_SIZE;
  SDL_FillRect(screen->screen, &screen->position, 0x00AA5005);
  pos.x = 0;
  pos.y = y + i;
  pos.h = 100;
  pos.w = SIDE_SIZE * CELL_SIZE;
  SDL_FillRect(screen->screen, &pos, color);
}

void		draw_cell(t_gui *screen, int x, int y, unsigned int color)
{
  screen->position.x = x * CELL_SIZE;
  screen->position.y = y * CELL_SIZE;
  screen->position.h = CELL_SIZE - 1;
  screen->position.w = CELL_SIZE - 1;
  SDL_FillRect(screen->screen, &screen->position, color);
}

void		blackout(t_gui *screen)
{
  SDL_Rect	pos;

  pos.x = CELL_SIZE * SIDE_SIZE;
  pos.y = 0;
  pos.w = 200;
  pos.h = CELL_SIZE * SIDE_SIZE + SIDE_SIZE;
  SDL_FillRect(screen->screen, &pos, 0x00000000);
  pos.x = 0;
  pos.y = CELL_SIZE * SIDE_SIZE;
  pos.w = 200 + CELL_SIZE * SIDE_SIZE;
  pos.h = SIDE_SIZE;
  SDL_FillRect(screen->screen, &pos, 0x00000000);
}

void		color_map(t_gui *screen, unsigned char *map)
{
  int		x;
  int		y;

  y = 0;
  while (y < SIDE_SIZE)
    {
      x = -1;
      while (++x < SIDE_SIZE)
	draw_cell(screen, x, y, screen->colour_array[(int)(map[POS(x, y)])]);
      ++y;
    }
  fulfill_team_array(screen, map);
  blackout(screen);
  information(screen, map);
  SDL_Flip(screen->screen);
}
