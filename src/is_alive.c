/*
** is_alive.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:52:18 2015 Hugo Prenat
** Last update Sun Mar  8 21:35:12 2015 Hugo Prenat
*/

#include "lemipc.h"

int	check_around(unsigned char *map, t_player *player, int x, int y)
{
  if (x == 0 && y == 0)
    return (0);
  if (player->x == 0 && x == -1)
    return (0);
  if (player->y == 0 && y == -1)
    return (0);
  if (player->x == SIDE_SIZE && x == 1)
    return (0);
  if (player->y == SIDE_SIZE && y == 1)
    return (0);
  if (map[POS(player->x + x, player->y + y)] != map[POS(player->x, player->y)])
    return (map[POS(player->x + x, player->y + y)]);
  return (0);
}

void	check_other(t_player *player, unsigned char *map, int *other)
{
  int	x;
  int	y;
  int	i;

  x = -1;
  i = 0;
  while (x != 2)
    {
      y = -1;
      while (y != 2)
	{
	  other[i] = check_around(map, player, x, y);
	  ++i;
	  ++y;
	}
      ++x;
    }
}

int	check_dead(int *other)
{
  int	i;
  int	j;
  int	dead;

  i = 0;
  dead = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	{
	  if (i != j && other[i] == other[j] && other[i] != 0)
	    dead++;
	  j++;
	}
      i++;
    }
  return (dead);
}

int	is_alive(t_player *player, unsigned char *map)
{
  int	other[9];

  memset(other, 0, sizeof(other));
  check_other(player, map, other);
  if (check_dead(other) >= 2)
    {
      change_state_sem(player, -1);
      map[POS(player->x, player->y)] = 0;
      change_state_sem(player, 1);
      return (-1);
    }
  return (0);
}
