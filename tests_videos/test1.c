/*
** test.c for test in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  1 06:34:43 2015 Johan Paasche
** Last update Sun Mar  1 07:18:52 2015 Johan Paasche
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
  int		sem_id;
  struct sembuf	sops;

  if (ac != 2)
    return (printf("[usage : %s pathname\n]", av[0]));

  key = ftok(av[1], 0);
  printf("Key = %d\n", key);

  sem_id = semget(key, 1, SHM_R |SHM_W);
  if (sem_id == -1)
    {
      sem_id = semget(key, 1, IPC_CREAT | SHM_R |SHM_W);
      printf("we created semaphore with %d id\n", sem_id);
      semctl(sem_id, 0, SETVAL, 4);
    }
  else
    {
      printf("Using semaphore with %d id\n", sem_id);
      sops.sem_num = 0;
      sops.sem_flg = 0;
      sops.sem_op = -1;
      printf("Before %d\n", semctl(sem_id, 0, GETVAL));
      semop(sem_id, &sops, 1);
      printf("After %d\n", semctl(sem_id, 0, GETVAL));
    }

  return (0);
}
