/*
** main.c for Test in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  1 22:03:00 2015 Johan Paasche
** Last update Sun Mar  1 23:43:14 2015 Johan Paasche
*/

#include	"lemiPC.h"

void		draw_cell(t_map *screen, int x, int y, unsigned int color)
{
  screen->position.x = x * CELL_SIZE;
  screen->position.y = y * CELL_SIZE;
  screen->position.h = CELL_SIZE;
  screen->position.w = CELL_SIZE;
  SDL_FillRect(screen->screen, &screen->position, 0x00AAAAAA);
  screen->position.x += 1;
  screen->position.y += 1;
  screen->position.w -= 1;
  screen->position.h -= 1;
  SDL_FillRect(screen->screen, &screen->position, color);
}

void		color_map(t_map *screen, void *addr)
{
  char		*map;
  int		x;
  int		y;

  x = 0;
  while (x < SIDE_SIZE)
    {
      y = 0;
      while (y < SIDE_SIZE)
	draw_cell(screen, x, y++, 0x000000);
      ++x;
    }
  SDL_Flip(screen->screen);
}

t_bool		map_display_init(t_map *map)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (FALSE);
  map->screen = SDL_SetVideoMode(SIDE_SIZE * CELL_SIZE + SIDE_SIZE, SIDE_SIZE * CELL_SIZE + SIDE_SIZE, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Collaborate or Die !", NULL);
  return (TRUE);
}

int		main(UNUSED int ac, UNUSED char **av)
{
  key_t		k;
  int		shm_id;
  void		*map;
  t_map		display_map;

  k = ftok(av[1], 0); /*je crée une clé d'un segment de mémoire de 42 * 42 */
  shm_id = shmget(k, MAP_SIZE, SHM_R | SHM_W);
  if (shm_id == FALSE)
    {
      shm_id = shmget(k, MAP_SIZE, IPC_CREAT | SHM_R | SHM_W);
      map = shmat(shm_id, NULL, SHM_R | SHM_W);
      int	i = 0;
      if (map_display_init(&display_map) == FALSE)
	return (-1);
      color_map(&display_map, NULL);
      sleep(5);
      while (i < MAP_SIZE)
  	{
  	  sprintf((char *)map, "%c", '0');
  	  ++i;
  	  (char*)map++;
  	}
    }
    else
    {
      map = shmat(shm_id, NULL, SHM_R | SHM_W);
      int	i = 0;
      while (i < MAP_SIZE)
  	{
  	  printf("[%c]", *(char*)map);
  	  ++i;
  	  (char*)map++;
  	  if (i % SIDE_SIZE == 0)
  	    printf("\n");
  	}
      /* printf("%s\n", (char *)map); */
      shmctl(shm_id, IPC_RMID, NULL);
    }
  return (0);
}
