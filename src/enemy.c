/*
** enemy.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Mar  8 15:17:20 2015 Hugo Prenat
** Last update Sun Mar  8 15:31:24 2015 Hugo Prenat
*/

#include "lemiPC.h"

void	try_move_up_down(t_player *player, unsigned char *map, int *x)
{
  /* if (map[POS(player->x - 1, player->y)] == 0) */
  /*   *x = player->x - 1; */
  /* else if (map[POS(player->x + 1, player->y)] == 0) */
  /*   *x = player->x + 1; */
  /* else */
  *x = player->x;
}

void	try_move_left_right(t_player *player, unsigned char *map, int *y)
{
  /* if (map[POS(player->x, player->y - 1)] == 0) */
  /*   *y = player->y - 1; */
  /* else if (map[POS(player->x, player->y + 1)] == 0) */
  /*   *y = player->y + 1; */
  /* else */
  *y = player->y;
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

  if ((enemy_pos = find_enemy(player, map)) == -1)
    return ;
  if ((unsigned int)enemy_pos % SIDE_SIZE > player->x &&
      map[POS(player->x + 1, player->y)] == 0)
    *x = player->x + 1;
  else if ((unsigned int)enemy_pos % SIDE_SIZE < player->x &&
	   map[POS(player->x - 1, player->y)] == 0)
    *x = player->x - 1;
  else
    try_move_up_down(player, map, x);
  if ((unsigned int)enemy_pos / SIDE_SIZE > player->y &&
      map[POS(player->x, player->y + 1)] == 0)
    *y = player->y + 1;
  else if ((unsigned int)enemy_pos / SIDE_SIZE < player->y &&
	   map[POS(player->x, player->y - 1)] == 0)
    *y = player->y - 1;
  else
    try_move_left_right(player, map, y);
}
