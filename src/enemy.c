/*
** enemy.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Mar  8 15:17:20 2015 Hugo Prenat
** Last update Sun Mar  8 18:56:47 2015 Hugo Prenat
*/

#include "lemiPC.h"

int	find_enemy(t_player *player, unsigned char *map)
{
  int	i;

  i = 0;
  while (i < MAP_SIZE)
    {
      if (map[i] != 0 && map[i] != player->team)
	return (i);
      i++;
    }
  return (-1);
}

void    try_move_diag(t_player *player, unsigned char *map, int *x, int *y)
{
  int	enemy_pos;

  enemy_pos = find_enemy(player, map);
  if ((unsigned int)enemy_pos % SIDE_SIZE <= player->x &&
      map[POS(player->x - 1, player->y - 1)] == 0)
    {
      *x = player->x - 1;
      *y = player->y - 1;
    }
  else if ((unsigned int)enemy_pos % SIDE_SIZE >= player->x &&
	   map[POS(player->x + 1, player->y + 1)] == 0)
    {
      *x = player->x + 1;
      *y = player->y + 1;
    }
  else if ((unsigned int)enemy_pos / SIDE_SIZE <= player->y &&
	   map[POS(player->x + 1, player->y - 1)] == 0)
    {
      *x = player->x + 1;
      *y = player->y - 1;
    }
}

void	go_to_enemy(t_player *player, unsigned char *map, int *x, int *y)
{
  int	enemy_pos;
  int	cant;

  cant = 0;
  if ((enemy_pos = find_enemy(player, map)) == -1)
    return ;
  if ((unsigned int)enemy_pos % SIDE_SIZE > player->x &&
      map[POS(player->x + 1, player->y)] == 0)
    *x = player->x + 1;
  else if ((unsigned int)enemy_pos % SIDE_SIZE < player->x &&
	   map[POS(player->x - 1, player->y)] == 0)
    *x = player->x - 1;
  else
    cant++;
  if ((unsigned int)enemy_pos / SIDE_SIZE > player->y &&
      map[POS(player->x, player->y + 1)] == 0)
    *y = player->y + 1;
  else if ((unsigned int)enemy_pos / SIDE_SIZE < player->y &&
	   map[POS(player->x, player->y - 1)] == 0)
    *y = player->y - 1;
  else
    cant++;
  if (cant > 1)
    try_move_diag(player, map, x, y);
}
