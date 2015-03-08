/*
** check_map.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Mar  8 16:13:51 2015 Hugo Prenat
** Last update Sun Mar  8 21:34:57 2015 Hugo Prenat
*/

#include "lemipc.h"

int	check_map(unsigned char *map)
{
  int	i;

  i = 0;
  while (i != MAP_SIZE)
    {
      if (map[i] == 0)
	return (0);
      i++;
    }
  return (-1);
}

t_bool	check_last(unsigned char *map)
{
  int	i;
  int	cnt;

  i = 0;
  cnt = 0;
  while (i < MAP_SIZE)
    {
      if (map[i] != 0)
	++cnt;
      if (cnt > 1)
	return (FALSE);
      ++i;
    }
  return (TRUE);
}
