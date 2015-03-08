/*
** gui.h for LemIPC in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Tue Mar  3 20:34:55 2015 Johan Paasche
** Last update Sun Mar  8 20:44:36 2015 Johan Paasche
*/

#ifndef		GUI_H_
# define	GUI_H_

# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<strings.h>

typedef	struct	s_gui
{
  SDL_Surface		*screen;
  SDL_Rect		position;
  SDL_Color		color;
  uint			colour_array[256];
  char			team_array[255];
  int			nb_team;
  /* pthread_t		event_thread; */
  SDL_Event		event;
  char			off;
  unsigned char		*map;
  TTF_Font		*font;
  key_t			key;
}		t_gui;

void		draw_cell(t_gui *, int, int, unsigned int);
void		color_map(t_gui *, unsigned char *);
void		shaded_grid(t_gui *, int);
void		lighting_circle(t_gui *, int);
void		init_colour_array(t_gui *);
void		fulfill_team_array(t_gui *, unsigned char *);
void		text(t_gui *, char *, int, int);
void		kill_remainings(t_gui *, unsigned char *);
void		information(t_gui *, unsigned char *);

#endif		/* !GUI_H_ */
