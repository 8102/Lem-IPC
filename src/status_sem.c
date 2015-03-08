/*
** status_sem.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:59:29 2015 Hugo Prenat
** Last update Sun Mar  8 21:35:25 2015 Hugo Prenat
*/

#include "lemipc.h"

void		change_state_sem(t_player *player, int state)
{
  struct sembuf	sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = state;
  semop(player->sem_id, &sops, 1);
}
