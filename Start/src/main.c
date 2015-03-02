/*
** main.c for Test in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  1 22:03:00 2015 Johan Paasche
** Last update Mon Mar  2 12:34:40 2015 Johan Paasche
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
  SDL_FillRect(screen->screen, &screen->position, 0x00AAAAAA);
  SDL_Flip(screen->screen);
  SDL_WM_SetCaption("Collaborate or Die !", NULL);
  return (TRUE);
}

int		main(UNUSED int ac, UNUSED char **av)
{
  key_t		k;
  int		shm_id;
  void		*map;
  void		*lol;
  t_map		display_map;

  k = ftok(av[1], 0);
  shm_id = shmget(k, MAP_SIZE, SHM_R | SHM_W);
  if (shm_id == FALSE)
    {
      srand(time(NULL));
      shm_id = shmget(k, MAP_SIZE, IPC_CREAT | SHM_R | SHM_W);
      map = shmat(shm_id, NULL, SHM_R | SHM_W);
      int	i = 0;
      lol = map;
      while (i < MAP_SIZE)
	{
  	  sprintf((char *)map, "%c", rand() % 5);
  	  ++i;
  	  (char*)map++;
  	}
    }
    else
    {
      map = shmat(shm_id, NULL, SHM_R | SHM_W);
      int	i = 0;
      if (map_display_init(&display_map) == FALSE)
      	return (-1);
      color_map(&display_map, (char *)map);
      sleep(5);
      printf(">\n");
      while (i < MAP_SIZE)
  	{
  	  printf("[%d]", (int)(*(char*)map));
  	  ++i;
  	  (char*)map++;
  	  if (i % SIDE_SIZE == 0)
  	    printf("\n");
  	}
      /* printf("%s\n", (char *)map); */
      shmctl(shm_id, IPC_RMID, NULL);
      SDL_FreeSurface(display_map.screen);
      SDL_Quit();
    }
  return (0);
}
