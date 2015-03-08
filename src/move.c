/*
** move.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:51:39 2015 Hugo Prenat
** Last update Sun Mar  8 13:12:57 2015 Hugo Prenat
*/

#include "lemiPC.h"

int	nearest_on_x(t_player *player, int d, unsigned char *map, int *y)
{
  int	i;
  int	x;

  i = 0;
  while (i < d)
    {
      if (map[POS(player->x - d + i, player->y - i)] != 0
	  && map[POS(player->x - d + i, player->y - i)] != player->team)
	{
	  x = player->x - d + 1;
	  *y = player->y - i;
	}
      else if (map[POS(player->x + d - i, player->y + i)] != 0
	       && map[POS(player->x + d - i, player->y + i)] != player->team)
	{
	  x = player->x + d - 1;
	  *y = player->y + i;
	}
      i++;
    }
  printf("x === %d\n", x);
  return (x);
}

int	nearest_on_y(t_player *player, int d, unsigned char *map, int *x)
{
  int	i;
  int	y;

  i = 0;
  while (i < d)
    {
      if (map[POS(player->x - i, player->y + d - i)] != 0
	  && map[POS(player->x - i, player->y + d - i)] != player->team)
	{
	  *x = player->x - 1;
	  y = player->y + d - i;
	}
      else if (map[POS(player->x + d - i, player->y - i)] != 0
	       && map[POS(player->x + d - i, player->y - i)] != player->team)
	{
	  *x = player->x + d - 1;
	  y = player->y - i;
	}
      i++;
    }
  printf("y === %d\n", y);
  return (y);
}

int	find_enemy(t_player *player, unsigned char *map)
{
  int	i;
  int	enemy_pos;

  enemy_pos = -1;
  i = 0;
  while (i < MAP_SIZE)
    {
      if (map[i] != 0 && map[i] != player->team)
	enemy_pos = i;
      i++;
    }
  return (enemy_pos);
}

void	go_to_enemy(t_player *player, unsigned char *map, int *x, int *y)
{
  int	enemy_pos;

  enemy_pos = find_enemy(player, map);
  nearest_on_x(player, map, x, y);
  nearest_on_y(player, map, x, y);
}

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
      sleep(1);
      /* usleep(100000); */
    }
}
