/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:24:00 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/22 12:25:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_env	g_env;

void	cleanup()
{
	if (g_env.shm <= 0 || !g_env.map || g_env.map == (void*)-1)
		return ;
	semlock();
	if (g_env.map->players_count > 1)
	{
		g_env.map->map[g_env.player_y][g_env.player_x].team = 0;
		g_env.map->map[g_env.player_y][g_env.player_x].player = 0;
		g_env.map->players_count--;
		shmdt(g_env.map);
		semunlock();
		return ;
	}
	shmdt(g_env.map);
	shmctl(g_env.shm, IPC_RMID, NULL);
	semctl(g_env.sem, 0, IPC_RMID);
	msgctl(g_env.msgq, IPC_RMID, NULL);
}

void	error_quit(char *error_message, char *file, int line)
{
	int	i;

	i = 0;
	while (i < MAP_HEIGHT + 4)
	{
		printf("\n");
		++i;
	}
	ft_putstr_fd("\033[1;31m", 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd(" (", 2);
	ft_putstr_fd(file, 2);
	ft_putchar_fd(':', 2);
	ft_putnbr_fd(line, 2);
	ft_putchar_fd(')', 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("\033[0m", 2);
	cleanup();
	exit(EXIT_FAILURE);
}
