/*0
** main.c for Test in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  1 22:03:00 2015 Johan Paasche
** Last update Tue Mar  3 17:41:09 2015 Johan Paasche
*/

#include	"lemiPC.h"

int		main(UNUSED int ac, UNUSED char **av)
{
  key_t		k;
  int		shm_id;
  void		*map;

  k = ftok(av[1], 0);
  shm_id = shmget(k, MAP_SIZE, SHM_R | SHM_W);
  if (shm_id == FALSE)
    {
      srand(time(NULL));
      shm_id = shmget(k, MAP_SIZE, IPC_CREAT | SHM_R | SHM_W);
      map = shmat(shm_id, NULL, SHM_R | SHM_W);
      memset(map, MAP_SIZE, 0);
      printf("Map created and initialized !\n");
      sprintf(map, "%c%c%c%c%c%c%c%c", 1, 0, 2, 0, 3, 0, 4, 0);
    }
    else
    {
      map = shmat(shm_id, NULL, SHM_R | SHM_W);
      printf("Map deleted !\n");
      shmctl(shm_id, IPC_RMID, NULL);
    }
  return (0);
}
