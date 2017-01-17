#include "lem_ipc.h"

t_env	g_env = {};

static void	place_player()
{
	while (1)
	{
		g_env.player_x = rand() / (float)RAND_MAX * MAP_WIDTH;
		g_env.player_y = rand() / (float)RAND_MAX * MAP_HEIGHT;
		if (!g_env.map->map[g_env.player_y][g_env.player_x].player)
		{
			g_env.map->map[g_env.player_y][g_env.player_x].player = g_env.player_id;
			g_env.map->map[g_env.player_y][g_env.player_x].team = g_env.team;
			break;
		}
	}
}

int 		main(int ac, char **av)
{
	ft_memset(&g_env, 0, sizeof(g_env));
	g_env.file = av[0];
	if (ac < 2 || !(g_env.team = ft_atoi(av[1])) || g_env.team > 9)
		ERROR("Invalid team id (must be non-null integer less than 10)");
	srand(time(NULL));
	initialize();
	semlock();
	if (g_env.map->players_count == MAP_WIDTH * MAP_HEIGHT)
		ERROR("Too much players");
	g_env.map->players_count++;
	g_env.map->total_players++;
	g_env.player_id = g_env.map->total_players;
	place_player();
	semunlock();
	while (1)
	{
		semlock();
		check_la_vie_c_est_nul();
		target_receive();
		action();
		display();
		semunlock();
		usleep(50000);
	}
}
