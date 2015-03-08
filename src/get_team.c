/*
** get_team.c for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Mar  8 21:19:58 2015 Hugo Prenat
** Last update Sun Mar  8 21:31:12 2015 Hugo Prenat
*/

#include "lemiPC.h"

int	get_team(char *str)
{
  int	team;

  srand(time(NULL));
  if (str)
    return (atoi(str));
  team = (rand() % 4) + 1;
  return (team);
}
