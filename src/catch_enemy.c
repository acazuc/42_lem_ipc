/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 07:28:59 by acazuc            #+#    #+#             */
/*   Updated: 2017/02/26 07:30:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_env	g_env;

static int	has_buddy(void)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (g_env.map->map[y][x].team == g_env.team)
				i++;
			++x;
		}
		++y;
	}
	return (i >= 2);
}

int			catch_enemy(void)
{
	if (!has_buddy())
	{
		g_env.target = 0;
		return (0);
	}
	target_check();
	if (!g_env.target)
	{
		target_search();
		if (!g_env.target)
			return (0);
		target_send();
	}
	target_find();
	if (!g_env.target)
		return (0);
	follow();
	return (1);
}
