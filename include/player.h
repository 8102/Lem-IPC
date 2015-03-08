/*
** player.h for LemiPC in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Tue Mar  3 18:05:40 2015 Johan Paasche
** Last update Sun Mar  8 21:22:46 2015 Hugo Prenat
*/

#ifndef		PLAYER_H_
# define	PLAYER_H_

# include	"lemiPC.h"

typedef	struct		s_player
{
  unsigned int		x;
  unsigned int		y;
  unsigned int		team;
  unsigned int		color;
  key_t			k;
  int			shm_id;
  int			sem_id;
}			t_player;

#endif		/* !PLAYER_H_ */
