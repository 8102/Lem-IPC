/*
** is_alive.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Thu Mar  5 18:52:18 2015 Hugo Prenat
** Last update Sat Mar  7 14:02:54 2015 Johan Paasche
*/

#include "lemiPC.h"

int	check_around(char *map, t_player *player, int x, int y)
{
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

void	check_other(t_player *player, char *map, int *other)
{
  int	x;
  int	y;
  int	i;

  x = -1;
  i = 0;
  while (x <= 1)
    {
      y = -1;
      while (y <= 1)
	{
	  if (x != 0 || y != 0)
	    {
	      other[i] = check_around(map, player, x, y);
	      ++i;
	    }
	  ++y;
	}
      ++x;
    }
}

/* void	check_other(t_player *player, char *map, int *other) */
/* { */
/*   if (map[POS(player->x - 1, player->y - 1)] != map[POS(player->x, player->y)]) */
/*     other[0] = map[POS(player->x - 1, player->y - 1)]; */
/*   if (map[POS(player->x, player->y - 1)] != map[POS(player->x, player->y)]) */
/*     other[1] = map[POS(player->x, player->y - 1)]; */
/*   if (map[POS(player->x + 1, player->y - 1)] != map[POS(player->x, player->y)]) */
/*     other[2] = map[POS(player->x + 1, player->y - 1)]; */
/*   if (map[POS(player->x - 1, player->y)] != map[POS(player->x, player->y)]) */
/*     other[3] = map[POS(player->x - 1, player->y)]; */
/*   if (map[POS(player->x + 1, player->y)] != map[POS(player->x, player->y)]) */
/*     other[4] = map[POS(player->x + 1, player->y)]; */
/*   if (map[POS(player->x - 1, player->y + 1)] != map[POS(player->x, player->y)]) */
/*     other[5] = map[POS(player->x, player->y + 1)]; */
/*   if (map[POS(player->x, player->y + 1)] != map[POS(player->x, player->y)]) */
/*     other[6] = map[POS(player->x, player->y + 1)]; */
/*   if (map[POS(player->x + 1, player->y + 1)] != map[POS(player->x, player->y)]) */
/*     other[7] = map[POS(player->x + 1, player->y + 1)]; */
/* } */

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
