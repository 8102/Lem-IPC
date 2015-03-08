/*
** check_map.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Mar  8 16:13:51 2015 Hugo Prenat
** Last update Sun Mar  8 16:15:50 2015 Hugo Prenat
*/

#include "lemiPC.h"

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
