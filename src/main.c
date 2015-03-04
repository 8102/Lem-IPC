/*
** main.c for Test in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  1 22:03:00 2015 Johan Paasche
** Last update Wed Mar  4 14:45:54 2015 Johan Paasche
*/

#include	"lemiPC.h"

int	init_player(t_player *player, char *map, int team)
{
  char	bool;

  bool = 0;
  if (team > 0 && team < 256)
    player->team = team;
  else
    {
      fprintf(stderr, "Error: team number must be between 1 and 255\n");
      return (-1);
    }
  while (bool == 0)
    {
      srand(time(NULL));
      player->x = rand() % SIDE_SIZE;
      player->y = rand() % SIDE_SIZE;
      if (map[POS(player->x, player->y)] == 0)
	{
	  map[POS(player->x, player->y)] = player->team;
	  bool = 1;
	}
    }
  return (0);
}

int		main(UNUSED int ac, UNUSED char **av)
{
  t_player	player;
  char		*map;
  char		cwd[PATH_MAX];

  if (ac < 2)
    {
      fprintf(stderr, "Usage: %s team_id\n", av[0]);
      return (-1);
    }
  if (getcwd(cwd, PATH_MAX) == NULL)
    return (-1);
  player.k = ftok(cwd, 0);
  player.shm_id = shmget(player.k, MAP_SIZE, SHM_R | SHM_W);
  if (player.shm_id == FALSE)
    {
      player.shm_id = shmget(player.k, MAP_SIZE, IPC_CREAT | SHM_R | SHM_W);
      map = shmat(player.shm_id, NULL, SHM_R | SHM_W);
      memset(map, MAP_SIZE, 0);
      printf("Map created and initialized !\n");
      if (init_player(&player, map, atoi(av[1])) == -1)
	return (-1);
      /* move(player, map); */
    }
  else if (av[1] && strcmp(av[1], "-d") == 0)
    {
      map = shmat(player.shm_id, NULL, SHM_R | SHM_W);
      printf("Map deleted !\n");
      shmctl(player.shm_id, IPC_RMID, NULL);
    }
  else
    {
      map = shmat(player.shm_id, NULL, SHM_R | SHM_W);
      printf("Map updated!\n");
      if (init_player(&player, map, atoi(av[1])) == -1)
	return (-1);
      /* move(player, map); */
    }
  return (0);
}
