/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 07:29:07 by acazuc            #+#    #+#             */
/*   Updated: 2017/02/26 07:31:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_env	g_env;

static void	print_map(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (g_env.map->map[y][x].team)
				printf("\033[1;3%dm %d", g_env.map->map[y][x].team % 7
						, g_env.map->map[y][x].team);
			else
				printf("\033[1;37m .");
			++x;
		}
		printf("\n");
		++y;
	}
}

void		display(void)
{
	int	i;

	printf("\033[1;37mShared memory id: \033[1;32m%d\033[0m\n", g_env.shm);
	printf("\033[1;37mSemaphore id: \033[1;33m%d\033[0m\n", g_env.sem);
	printf("\033[1;37mMessage queue id: \033[1;31m%d\033[0m\n", g_env.msgq);
	printf("\n");
	print_map();
	i = 0;
	while (i < 4 + MAP_HEIGHT)
	{
		printf("\033[A");
		++i;
	}
}
