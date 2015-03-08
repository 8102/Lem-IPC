/*
** move.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:51:39 2015 Hugo Prenat
** Last update Sun Mar  8 19:36:08 2015 Johan Paasche
*/

#include "lemiPC.h"

void	update_player_pos(int x, int y, t_player *player, unsigned char *map)
{
  int	mem_x;
  int	mem_y;

  mem_x = player->x;
  mem_y = player->y;
  if (map[POS(x, y)] != 0 || x >= SIDE_SIZE || y >= SIDE_SIZE
      || x < 0 || y < 0)
    return ;
  player->x = x;
  player->y = y;
  map[POS(player->x, player->y)] = player->team;
  map[POS(mem_x, mem_y)] = 0;
}

void		move(t_player *player, unsigned char *map)
{
  int		x;
  int		y;
  t_message	mail;
  int		msg_id;

  x = player->x;
  y = player->y;
  while (is_alive(player, map) == 0)
    {
      /* msg_id = msgget(player->k, SHM_R | SHM_W); */
      /* if (msg_id == -1) */
      /* 	msg_id = msgget(player->k, IPC_CREAT | SHM_R | SHM_W); */
      /* msgrcv(msg_id, &mail, sizeof(mail), player->team, IPC_NOWAIT); */
      /* if (mail.to_die == TRUE) */
      /* 	{ */
      /* 	  printf("message to die [%d]\n", player->team); */
      /* 	  break; */
      /* 	} */
      change_state_sem(player, -1);
      go_to_enemy(player, map, &x, &y);
      update_player_pos(x, y, player, map);
      change_state_sem(player, 1);
      usleep(100000);
    }
}
