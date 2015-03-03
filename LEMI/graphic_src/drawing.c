/*
** drawing.c for LemIPC in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Mon Mar  2 01:12:37 2015 Johan Paasche
** Last update Tue Mar  3 17:39:34 2015 Johan Paasche
*/

#include	"lemiPC.h"

void		draw_cell(t_map *screen, int x, int y, unsigned int color)
{
  screen->position.x = x * CELL_SIZE;
  screen->position.y = y * CELL_SIZE;
  screen->position.h = CELL_SIZE - 1;
  screen->position.w = CELL_SIZE - 1;
  SDL_FillRect(screen->screen, &screen->position, color);
}

void		color_map(t_map *screen, UNUSED char *map)
{
  int		x;
  int		y;
  unsigned int 	color[5] = {0x22222222, 0x00FF21B1, 0x003cff19, 0X00FFFF47, 0x00FF0505};

  y = 0;
  while (y < SIDE_SIZE)
    {
      x = -1;
      while (++x < SIDE_SIZE)
	{
	  draw_cell(screen, x, y, color[(int)(map[POS(x, y)]) % 5]);
	  /* draw_cell(screen, x, y, 0x22222222); */
	}
      ++y;
    }
  SDL_Flip(screen->screen);
}
