/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 07:29:37 by acazuc            #+#    #+#             */
/*   Updated: 2017/02/26 07:42:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_env	g_env;

void	target_check(void)
{
	int	x;
	int	y;

	if (!g_env.target)
		return ;
	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (g_env.map->map[y][x].player == g_env.target)
				return ;
			++x;
		}
		++y;
	}
	g_env.target = 0;
}

void	target_find(void)
{
	int	x;
	int	y;

	g_env.target_x = 0;
	g_env.target_y = 0;
	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (g_env.map->map[y][x].player == g_env.target)
			{
				g_env.target_x = x;
				g_env.target_y = y;
				return ;
			}
			++x;
		}
		++y;
	}
	g_env.target = 0;
}

void	target_search(void)
{
	int	y;
	int	x;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (g_env.map->map[y][x].team && g_env.map->map[y][x].team
					!= g_env.team)
			{
				g_env.target = g_env.map->map[y][x].player;
				return ;
			}
			++x;
		}
		++y;
	}
}

void	target_send(void)
{
	t_msg	msg;
	int		y;
	int		x;

	msg.target = g_env.target;
	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (g_env.map->map[y][x].team == g_env.team)
			{
				msg.player = g_env.map->map[y][x].player;
				if (msgsnd(g_env.msgq, &msg, sizeof(msg) - sizeof(long)
							, IPC_NOWAIT) == -1 && errno != EAGAIN)
					ERROR("msgsng() failed");
			}
			++x;
		}
		++y;
	}
}

void	target_receive(void)
{
	t_msg	msg;

	if (msgrcv(g_env.msgq, &msg, sizeof(msg) - sizeof(long), g_env.player_id
				, IPC_NOWAIT) == -1)
	{
		if (errno != EAGAIN && errno != ENOMSG)
			ERROR("msgrcv() failed");
		return ;
	}
	g_env.target = msg.target;
}
