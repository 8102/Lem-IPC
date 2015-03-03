/*
** graphic_client.c for LemiPC in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Mon Mar  2 16:40:52 2015 Johan Paasche
** Last update Mon Mar  2 16:54:53 2015 Johan Paasche
*/

#include	"lemiPC.h"

int		main(int ac, char **av)
{
  key_t		key;
  t_map		screen;
  int		shm_id;
  void		*map;

  key = ftok(av[1], 0);
  shm_id = shmget(key, MAP_SIZE, SHM_R);
  if (shm_id == FALSE)
    return (sprintf(stderr, "Please init the map before launching graphic client.\n"));
  if (map_display_init(&screen) == FALSE)
    return (sprintf(stderr, "A problem has occured while initing Graphic client.\n"));
  map = shmat(shm_id, NULL, SHM_R);
  color_map(&screen, (char *)map);
  sleep(5);
  return (0);
}
