/*
** testmsg.c for  in /home/paasch_j/work/PSU/PSU_2014_lemipc/msg
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  1 21:40:51 2015 Johan Paasche
** Last update Sun Mar  1 21:59:07 2015 Johan Paasche
*/

#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/shm.h>
#include	<sys/msq.h>
#include	<stdio.h>


int		main(int ac, char **av)
{
  key_t		k;

  int		msg_id;

  k = ftok(av[1], 0);

  msg_id = msgget(k, SHM_R | SHM_W);
  if (msg_id == -1)
    {
      msg_id = msgget(k, IPC_CREAT | SHM_R | SHM_W);

    }

  else
    msgctl(msg_id, IPC_RMID, NULL);
  return (0);
}
