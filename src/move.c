/*
** move.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:51:39 2015 Hugo Prenat
** Last update Thu Mar  5 18:53:07 2015 Hugo Prenat
*/

#include "lemiPC.h"

void	update_player_pos(int x, int y, t_player *player, char *map)
{
  if (map[POS(player->x, player->y)] != 0)
    return ;
  player->x = x;
  player->y = y;
  map[POS(player->x, player->y)] = player->team;
}

void	move(t_player *player, char *map)
{
  while (is_alive(player, map) == 0)
    {
      change_state_sem(player, -1);
      update_player_pos(player->x + 1, player->y + 1, player, map);
      change_state_sem(player, 1);
      usleep(100000);
    }
}
