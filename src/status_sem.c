/*
** status_sem.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:59:29 2015 Hugo Prenat
** Last update Thu Mar  5 18:59:46 2015 Hugo Prenat
*/

#include "lemiPC.h"

void		change_state_sem(t_player *player, int state)
{
  struct sembuf	sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = state;
  semop(player->sem_id, &sops, 1);
}
