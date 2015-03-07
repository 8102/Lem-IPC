/*
** move.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:51:39 2015 Hugo Prenat
** Last update Sat Mar  7 17:05:34 2015 Hugo Prenat
*/

#include "lemiPC.h"

/* void	go_to_enemy(t_player *player) */
/* { */
/*   int	x_enemy; */
/*   int	y_enemy; */
/*   x_enemy = 0; */
/*   y_enemy = 0; */
/*   if (player->y > y_enemy) */
/*     player->y += 1; */
/*   else if */
/*     player->y -= 1; */
/* } */

void	update_player_pos(int x, int y, t_player *player, char *map)
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

void	move(t_player *player, char *map)
{
  while (is_alive(player, map) == 0)
    {
      change_state_sem(player, -1);
      update_player_pos(player->x + rand() % 2, player->y + rand() % 2,
			player, map);
      change_state_sem(player, 1);
      usleep(100000);
    }
}
