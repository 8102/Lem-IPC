/*
** test.c for test in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  1 06:34:43 2015 Johan Paasche
** Last update Sun Mar  1 07:11:59 2015 Johan Paasche
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<pthread.h>
#include	<sys/ipc.h>
#include	<sys/types.h>
#include	<sys/shm.h>
#include	<sys/sem.h>

int		main(int ac, char **av)
{
  key_t		key;
  int		shm_id;
  void		*addr;

  if (ac != 2)
    return (printf("[usage : %s pathname\n]", av[0]));

  key = ftok(av[1], 0);
  printf("Key = %d\n", key);

  shm_id = shmget(key, 42, SHM_R |SHM_W);
  /* if (shm_id == -1) */
  /*   { */
  /*     shm_id = shmget(key, 42, IPC_CREAT | SHM_R | SHM_W); */
  /*     printf("Created the segment %d\n", shm_id); */
  /*     addr = shmat(shm_id, NULL, SHM_R | SHM_W); */
  /*     sprintf((char *)addr, "I love ponies!"); */
  /*   } */
  /* else */
  /*   { */
  /*     printf("Using SHM segment %d\n", shm_id); */
  /*     addr = shmat(shm_id, NULL, SHM_R | SHM_W); */
  /*     printf("-----> %s\n", (char *)addr); */
  /*     shmctl(shm_id, IPC_RMID, NULL); */
  /*   } */
  return (0);
}
