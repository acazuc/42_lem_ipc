#include "lem_ipc.h"

t_env	g_env;

int	can_left()
{
	if (g_env.player_x <= 0
		|| g_env.map->map[g_env.player_y][g_env.player_x - 1].player)
		return (0);
	return (1);
}

int	can_right()
{
	if (g_env.player_x >= MAP_WIDTH - 1
		|| g_env.map->map[g_env.player_y][g_env.player_x + 1].player)
		return (0);
	return (1);
}

int	can_top()
{
	if (g_env.player_y <= 0
		|| g_env.map->map[g_env.player_y - 1][g_env.player_x].player)
		return (0);
	return (1);
}

int	can_bottom()
{
	if (g_env.player_y >= MAP_HEIGHT - 1
		|| g_env.map->map[g_env.player_y + 1][g_env.player_x].player)
		return (0);
	return (1);
}
