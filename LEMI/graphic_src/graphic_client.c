/*
** graphic_client.c for LemiPC in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Mon Mar  2 16:40:52 2015 Johan Paasche
** Last update Tue Mar  3 17:33:29 2015 Johan Paasche
*/

#include	"lemiPC.h"

t_bool		map_display_init(t_map *screen)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (FALSE);
  screen->screen = SDL_SetVideoMode(SIDE_SIZE * CELL_SIZE + 200, SIDE_SIZE * CELL_SIZE + SIDE_SIZE, 32, SDL_HWSURFACE);
  screen->position.x = 0;
  screen->position.y = 0;
  screen->position.h = SIDE_SIZE * CELL_SIZE;
  screen->position.w = SIDE_SIZE * CELL_SIZE;
  SDL_FillRect(screen->screen, &screen->position, 0x00AA5005);
  SDL_Flip(screen->screen);
  SDL_WM_SetCaption("COLLABORATE OR PERISH !", NULL);
  return (TRUE);
}

int		main(UNUSED int ac, UNUSED char **av)
{
  key_t		key;
  t_map		screen;
  int		shm_id;
  void		*map;

  key = ftok(av[1], 0);
  shm_id = shmget(key, MAP_SIZE, SHM_R | SHM_W);
  if (shm_id == FALSE)
    return (printf("Please init the map before launching graphic client.\n"));
  if (map_display_init(&screen) == FALSE)
    return (printf("A problem has occured while initing Graphic client.\n"));
  map = shmat(shm_id, NULL, SHM_R | SHM_W);
  color_map(&screen, (char *)map);
  sleep(5);
  return (0);
}
