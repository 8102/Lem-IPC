/*
** is_alive.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:52:18 2015 Hugo Prenat
** Last update Thu Mar  5 18:54:25 2015 Hugo Prenat
*/

#include "lemiPC.h"

void	check_other(t_player *player, char *map, int *other)
{
  if (map[POS(player->x - 1, player->y - 1)] != map[POS(player->x, player->y)])
    other[0] = map[POS(player->x - 1, player->y - 1)];
  if (map[POS(player->x, player->y - 1)] != map[POS(player->x, player->y)])
    other[1] = map[POS(player->x, player->y - 1)];
  if (map[POS(player->x + 1, player->y - 1)] != map[POS(player->x, player->y)])
    other[2] = map[POS(player->x + 1, player->y - 1)];
  if (map[POS(player->x - 1, player->y)] != map[POS(player->x, player->y)])
    other[3] = map[POS(player->x - 1, player->y)];
  if (map[POS(player->x + 1, player->y)] != map[POS(player->x, player->y)])
    other[4] = map[POS(player->x + 1, player->y)];
  if (map[POS(player->x - 1, player->y + 1)] != map[POS(player->x, player->y)])
    other[5] = map[POS(player->x, player->y + 1)];
  if (map[POS(player->x, player->y + 1)] != map[POS(player->x, player->y)])
    other[6] = map[POS(player->x, player->y + 1)];
  if (map[POS(player->x + 1, player->y + 1)] != map[POS(player->x, player->y)])
    other[7] = map[POS(player->x + 1, player->y + 1)];
}

int	check_dead(int *other)
{
  int	i;
  int	j;
  int	dead;

  i = 0;
  dead = 0;
  while (other[i])
    {
      j = 0;
      while (other[j])
	{
	  if (j != i && other[i] == other[j] && other[i] != 0 && other[j] != 0)
	    dead++;
	  j++;
	}
      i++;
    }
  return (dead);
}

int	is_alive(t_player *player, char *map)
{
  int	other[9];

  memset(other, 0, sizeof(other));
  check_other(player, map, other);
  if (check_dead(other) > 2)
    {
      change_state_sem(player, -1);
      map[POS(player->x, player->y)] = 0;
      change_state_sem(player, 1);
      return (-1);
    }
  return (0);
}
