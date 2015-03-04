/*
** lemiPC.h for  in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  1 22:07:05 2015 Johan Paasche
** Last update Wed Mar  4 14:16:43 2015 Hugo Prenat
*/

#ifndef		LEMIPC_H_
# define	LEMIPC_H_

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<linux/limits.h>

# include	<sys/types.h>
# include	<sys/shm.h>
# include	<sys/ipc.h>
# include	<pthread.h>

# include	"player.h"
# include	"gui.h"

/*
** Just to avoid some warnings
*/

# define	UNUSED		__attribute__((unused))

/*
** I like it sometimes
*/

typedef		char		t_bool;

# define	TRUE		(1)
# define	FALSE		(-1)

/*
** Just to test
*/
# define	SIDE_SIZE	(42)
# define	MAP_SIZE	(SIDE_SIZE * SIDE_SIZE)

/*
** to move in the map in a safe way, e.g : map[SAFE(x)].
** Avoid any segfault :p
*/

# define	ABS(x)		((x) < 0 ? (-1 * (x)) : (x))
# define	SAFE(x)		((x) % (MAP_SIZE))
/* # define	SAFE(x)		((ABS(x)) % (MAP_SIZE)) */

/*
** map[POS(4, 5)] = map[5 * 42 + 4];
*/
# define	X(x)		(((SAFE(x)) % SIDE_SIZE))
# define	Y(x)		(((SAFE(x)) % SIDE_SIZE) * SIDE_SIZE)
# define	POS(x, y)	((X(x)) + (Y(y)))

/*
** size, in pxl, of a cell in the map
*/
# define	CELL_SIZE	(20)

#endif		/* !LEMIPC_H_ */
