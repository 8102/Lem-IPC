/*
** gui.h for LemIPC in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Tue Mar  3 20:34:55 2015 Johan Paasche
** Last update Fri Mar  6 16:17:11 2015 Johan Paasche
*/

#ifndef		GUI_H_
# define	GUI_H_

# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>

typedef	struct	s_gui
{
  SDL_Surface	*screen;
  SDL_Rect	position;
  SDL_Color	color;
  uint		colour_array[256];
  pthread_t	event_thread;
  char		off;
  char		*map;
}		t_gui;

void		draw_cell(t_gui *, int, int, unsigned int);
void		color_map(t_gui *, char *);
void		shaded_grid(t_gui *, int);
void		lighting_circle(t_gui *, int);
void		init_colour_array(t_gui *);

#endif		/* !GUI_H_ */
