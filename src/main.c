/*
** main.c for lemipc in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  1 22:03:00 2015 Johan Paasche
** Last update Thu Mar  5 21:53:43 2015 Johan Paasche
*/

#include "lemiPC.h"

void	delete_ipc(t_player *player)
{
  if (player->shm_id != -1)
    {
      printf("Map deleted !\n");
      shmctl(player->shm_id, IPC_RMID, NULL);
    }
  else
    printf("Can't delete anything\n");
}

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
      /* printf("x = [%d] y = [%d] POS = [%d] \n", player->x, player->y, POS(player->x, player->y)/\*, map[POS(player->x, player->y)]*\/); */
      if (map[POS(player->x, player->y)] == 0)
	{
	  map[POS(player->x, player->y)] = player->team;
	  bool = 1;
	}
    }
  return (0);
}

char	*init_ipc(t_player *player)
{
  char *map;

  player->shm_id = shmget(player->k, MAP_SIZE, IPC_CREAT | SHM_R | SHM_W);
  player->sem_id = semget(player->k, 1, IPC_CREAT | SHM_R | SHM_W);
  map = shmat(player->shm_id, NULL, SHM_R | SHM_W);
  semctl(player->sem_id, 0, SETVAL, 1);
  memset(map, 0, MAP_SIZE);
  return (map);
}

int	get_token(t_player *player)
{
  char		cwd[PATH_MAX];

  if (getcwd(cwd, PATH_MAX) == NULL)
    return (-1);
  player->k = ftok(cwd, 0);
  player->shm_id = shmget(player->k, MAP_SIZE, SHM_R | SHM_W);
  player->sem_id = semget(player->k, 1, SHM_R | SHM_W);
  return (0);
}

int		main(UNUSED int ac, UNUSED char **av)
{
  t_player	player;
  char		*map;

  if (ac < 2)
    {
      fprintf(stderr, "Usage: %s team_id\n", av[0]);
      return (-1);
    }
  map = NULL;
  if (get_token(&player) == -1)
    return (-1);
  if (av[1] && strcmp(av[1], "-d") == 0)
    delete_ipc(&player);
  else if (player.shm_id == FALSE)
    map = init_ipc(&player);
  else
    map = shmat(player.shm_id, NULL, SHM_R | SHM_W);
  if (init_player(&player, map, atoi(av[1])) == -1)
    return (-1);
  move(&player, map);
  return (0);
}
