/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 07:29:24 by acazuc            #+#    #+#             */
/*   Updated: 2017/02/26 07:38:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_env	g_env;

void	go_left(void)
{
	g_env.map->map[g_env.player_y][g_env.player_x].player = 0;
	g_env.map->map[g_env.player_y][g_env.player_x].team = 0;
	g_env.player_x--;
	g_env.map->map[g_env.player_y][g_env.player_x].player = g_env.player_id;
	g_env.map->map[g_env.player_y][g_env.player_x].team = g_env.team;
}

void	go_right(void)
{
	g_env.map->map[g_env.player_y][g_env.player_x].player = 0;
	g_env.map->map[g_env.player_y][g_env.player_x].team = 0;
	g_env.player_x++;
	g_env.map->map[g_env.player_y][g_env.player_x].player = g_env.player_id;
	g_env.map->map[g_env.player_y][g_env.player_x].team = g_env.team;
}

void	go_top(void)
{
	g_env.map->map[g_env.player_y][g_env.player_x].player = 0;
	g_env.map->map[g_env.player_y][g_env.player_x].team = 0;
	g_env.player_y--;
	g_env.map->map[g_env.player_y][g_env.player_x].player = g_env.player_id;
	g_env.map->map[g_env.player_y][g_env.player_x].team = g_env.team;
}

void	go_bottom(void)
{
	g_env.map->map[g_env.player_y][g_env.player_x].player = 0;
	g_env.map->map[g_env.player_y][g_env.player_x].team = 0;
	g_env.player_y++;
	g_env.map->map[g_env.player_y][g_env.player_x].player = g_env.player_id;
	g_env.map->map[g_env.player_y][g_env.player_x].team = g_env.team;
}
