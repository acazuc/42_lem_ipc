#include "lem_ipc.h"

t_env	g_env;

static int	has_buddy()
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

int		catch_enemy()
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
