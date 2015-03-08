/*
** manage.c for LEMIPC in /home/paasch_j/work/PSU/PSU_2014_lemipc
**
** Made by Johan Paasche
** Login   <paasch_j@epitech.net>
**
** Started on  Sun Mar  8 17:13:54 2015 Johan Paasche
** Last update Sun Mar  8 20:52:48 2015 Johan Paasche
*/

#include	"lemiPC.h"

void		fulfill_team_array(t_gui *screen, unsigned char *map)
{
  int		i;

  i = 0;
  while (i < 255)
    {
      screen->team_array[i] = 0;
      ++i;
    }
  i = 0;
  while (map && i < MAP_SIZE)
    {
      if (map[i] != 0)
	screen->team_array[(int)map[i] % 256] = 1;
      ++i;
    }
}

t_bool		send_kill_mail(t_gui *screen, int nb)
{
  t_message	mail;
  int		msg_id;

  msg_id = msgget(screen->key, SHM_R |SHM_W);
  if (msg_id == -1)
    msg_id = msgget(screen->key, IPC_CREAT | SHM_R |SHM_W);
  mail.mtype = nb + 1;
  mail.to_die = TRUE;
  mail.target_x = 0;
  mail.target_y = 0;
  msgsnd(msg_id, &mail, sizeof(mail), 0);
  msgctl(msg_id, IPC_RMID, NULL);
  return (TRUE);
}

void		kill_remainings(t_gui *screen, unsigned char *map)
{
  int		i;

  i = 0;
  fulfill_team_array(screen, map);
  while (i < 255)
    {
      if (screen->team_array[i] == 1)
	send_kill_mail(screen, i);
      ++i;
    }
}
