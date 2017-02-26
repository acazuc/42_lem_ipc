/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pussybilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 07:29:27 by acazuc            #+#    #+#             */
/*   Updated: 2017/02/26 07:34:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_env	g_env;

int	can_left(void)
{
	if (g_env.player_x <= 0
		|| g_env.map->map[g_env.player_y][g_env.player_x - 1].player)
		return (0);
	return (1);
}

int	can_right(void)
{
	if (g_env.player_x >= MAP_WIDTH - 1
		|| g_env.map->map[g_env.player_y][g_env.player_x + 1].player)
		return (0);
	return (1);
}

int	can_top(void)
{
	if (g_env.player_y <= 0
		|| g_env.map->map[g_env.player_y - 1][g_env.player_x].player)
		return (0);
	return (1);
}

int	can_bottom(void)
{
	if (g_env.player_y >= MAP_HEIGHT - 1
		|| g_env.map->map[g_env.player_y + 1][g_env.player_x].player)
		return (0);
	return (1);
}
