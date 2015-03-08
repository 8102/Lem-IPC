/*
** move.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:51:39 2015 Hugo Prenat
** Last update Sun Mar  8 15:16:46 2015 Hugo Prenat
*/

#include "lemiPC.h"

void	update_player_pos(int x, int y, t_player *player, unsigned char *map)
{
  int	mem_x;
  int	mem_y;

  mem_x = player->x;
  mem_y = player->y;
  if (map[POS(x, y)] != 0 || x >= SIDE_SIZE || y >= SIDE_SIZE)
    return ;
  player->x = x;
  player->y = y;
  map[POS(player->x, player->y)] = player->team;
  map[POS(mem_x, mem_y)] = 0;
}

void	move(t_player *player, unsigned char *map)
{
  int	x;
  int	y;

  while (is_alive(player, map) == 0)
    {
      change_state_sem(player, -1);
      go_to_enemy(player, map, &x, &y);
      update_player_pos(x, y, player, map);
      change_state_sem(player, 1);
      usleep(100000);
    }
}
