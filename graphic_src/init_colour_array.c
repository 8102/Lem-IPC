/*
** init_colour_array.c for Lemipc in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Fri Mar  6 16:05:14 2015 Johan Paasche
** Last update Sat Mar  7 18:07:11 2015 Johan Paasche
*/

#include	"lemiPC.h"
#include	"gui.h"

void		init_colour_array(t_gui *screen)
{
  int		i;
  FILE		*fd;
  t_bool	correct_file;
  char		str[32];

  correct_file = FALSE;
  if ((fd = fopen(".colors", "r")) != NULL)
    correct_file = TRUE;
  i = 0;
  while (i < 256)
    {
      if (correct_file == TRUE)
	{
	  if (!(fgets(str, sizeof(str), fd)))
	    screen->colour_array[i % 256] = rand();
	  else
	    screen->colour_array[i % 256] = strtol(str, NULL, 16);
	}
      else
	screen->colour_array[i % 256] = rand();
      ++i;
    }
  screen->colour_array[0] = 0x22222222;
}
