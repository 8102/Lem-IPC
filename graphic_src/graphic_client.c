/*
** graphic_client.c for LemiPC in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Mon Mar  2 16:40:52 2015 Johan Paasche
** Last update Sun Mar  8 21:36:44 2015 Hugo Prenat
*/

#include	"lemipc.h"

t_bool		check_end(char *map)
{
  int		i;
  int		nb_teams;

  i = 0;
  nb_teams = 0;
  while (i < MAP_SIZE)
    {
      if (map[i] != 0 && map[i] != 'X')
	{
	  if (nb_teams == 0)
	    nb_teams = map[i];
	  else
	    return (FALSE);
	}
      ++i;
    }
  return (TRUE);
}

t_bool		map_display_init(t_gui *screen)
{
  screen->off = FALSE;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (FALSE);
  screen->screen = SDL_SetVideoMode(SIDE_SIZE * CELL_SIZE + 200,
				    SIDE_SIZE * CELL_SIZE + SIDE_SIZE,
				    32, SDL_HWSURFACE);
  screen->position.x = 0;
  screen->position.y = 0;
  screen->position.h = SIDE_SIZE * CELL_SIZE;
  screen->position.w = SIDE_SIZE * CELL_SIZE;
  SDL_FillRect(screen->screen, &screen->position, 0x00AA5005);
  SDL_Flip(screen->screen);
  SDL_WM_SetCaption("COLLABORATE OR PERISH !", NULL);
  init_colour_array(screen);
  if (TTF_Init() == -1)
    return (FALSE);
  if (!(screen->font = TTF_OpenFont(".font.ttf", 20)))
    return (FALSE);
  bzero(screen->team_array, 255);
  return (TRUE);
}

void		display_loop(t_gui *screen)
{
  int		i;

  i = 0;
  while (screen->off == FALSE)
    {
      SDL_PollEvent(&screen->event);
      if (screen->event.key.keysym.sym == SDLK_ESCAPE)
	{
	  screen->off = TRUE;
	  break;
	}
      shaded_grid(screen, i % (CELL_SIZE * SIDE_SIZE - 100));
      color_map(screen, screen->map);
      usleep(10000);
      ++i;
    }
}

int		main()
{
  key_t		key;
  t_gui		screen;
  int		shm_id;
  char		cwd[1024];

  srand(time(NULL));
  if (getcwd(cwd, sizeof(cwd)) == NULL)
    return (-1);
  key = ftok(cwd, 0);
  shm_id = shmget(key, MAP_SIZE, SHM_R | SHM_W);
  if (shm_id == -1)
    return (printf("Please init the map before launching graphic client.\n"));
  if (map_display_init(&screen) == FALSE)
    return (printf("A problem has occured while initing Graphic client.\n"));
  screen.map = shmat(shm_id, NULL, SHM_R | SHM_W);
  color_map(&screen, screen.map);
  screen.key = key;
  display_loop(&screen);
  SDL_Quit();
  kill_remainings(&screen,screen.map);
  return (0);
}
