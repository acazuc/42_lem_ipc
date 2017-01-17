#include "lem_ipc.h"

t_env	g_env;

int	go_left()
{
	g_env.map->map[g_env.player_y][g_env.player_x].player = 0;
	g_env.map->map[g_env.player_y][g_env.player_x].team = 0;
	g_env.player_x--;
	g_env.map->map[g_env.player_y][g_env.player_x].player = g_env.player_id;
	g_env.map->map[g_env.player_y][g_env.player_x].team = g_env.team;
	return (1);
}

int	go_right()
{
	g_env.map->map[g_env.player_y][g_env.player_x].player = 0;
	g_env.map->map[g_env.player_y][g_env.player_x].team = 0;
	g_env.player_x++;
	g_env.map->map[g_env.player_y][g_env.player_x].player = g_env.player_id;
	g_env.map->map[g_env.player_y][g_env.player_x].team = g_env.team;
	return (1);
}

int	go_top()
{
	g_env.map->map[g_env.player_y][g_env.player_x].player = 0;
	g_env.map->map[g_env.player_y][g_env.player_x].team = 0;
	g_env.player_y--;
	g_env.map->map[g_env.player_y][g_env.player_x].player = g_env.player_id;
	g_env.map->map[g_env.player_y][g_env.player_x].team = g_env.team;
	return (1);
}

int	go_bottom()
{
	g_env.map->map[g_env.player_y][g_env.player_x].player = 0;
	g_env.map->map[g_env.player_y][g_env.player_x].team = 0;
	g_env.player_y++;
	g_env.map->map[g_env.player_y][g_env.player_x].player = g_env.player_id;
	g_env.map->map[g_env.player_y][g_env.player_x].team = g_env.team;
	return (1);
}
