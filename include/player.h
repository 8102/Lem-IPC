/*
** player.h for LemiPC in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Tue Mar  3 18:05:40 2015 Johan Paasche
** Last update Tue Mar  3 18:08:30 2015 Johan Paasche
*/

#ifndef		PLAYER_H_
# define	PLAYER_H_

# include	"lemiPC.h"

typedef	struct	s_player
{
  unsigned int		x;
  unsigned int		y;
  unsigned int		team;
  unsigned int		color;
  struct s_player	*leader;
}		t_player;

#endif		/* !PLAYER_H_ */
