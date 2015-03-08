/*
** signal.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Mar  8 20:12:58 2015 Hugo Prenat
** Last update Sun Mar  8 21:02:34 2015 Hugo Prenat
*/

#include "lemiPC.h"

t_player		*player_struct(t_player *ptr)
{
  static t_player	*player = NULL;

  if (ptr == NULL)
    return (player);
  player = ptr;
  return (NULL);
}

void		end_process(int sig)
{
  t_player	*player;
  unsigned char	*map;

  if (sig != SIGINT)
    return ;
  if ((player = player_struct(NULL)) == NULL)
    return ;
  map = shmat(player->shm_id, NULL, SHM_R | SHM_W);
  change_state_sem(player, -1);
  printf("x === %d y === %d\n", player->x, player->y);
  map[POS(player->x, player->y)] = 0;
  if (check_map(map) == 0)
    {
      change_state_sem(player, 1);
      delete_ipc(player);
      exit (EXIT_SUCCESS);
    }
  change_state_sem(player, 1);
  exit (EXIT_SUCCESS);
}
