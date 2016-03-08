/*
** my_putstr.c for PUTSTR in /home/bougon_p/rendu/CPE_2015_Allum1/lib/my
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Feb 18 16:44:34 2016 bougon_p
** Last update Tue Mar  8 01:20:11 2016 Clémenceau Cedric
*/

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
