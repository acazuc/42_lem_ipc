#include "lem_ipc.h"

t_env	g_env;

static void	exit_youhou()
{
	int	i;

	display();
	i = 0;
	while (i < MAP_HEIGHT + 4)
	{
		printf("\n\033[0m");
		++i;
	}
}

static void	check_team(int *teams, int team)
{
	int	i;

	i = 0;
	while (i < 9 && teams[i])
	{
		if (teams[i] == team)
		{
			exit_youhou();
			cleanup();
			exit(EXIT_SUCCESS);
		}
		++i;
	}
	teams[i] = team;
}

static void	do_check(int *teams, int x, int y)
{
	if (g_env.player_y + y < 0 || g_env.player_y + y > MAP_HEIGHT - 1
		|| g_env.player_x + x < 0 || g_env.player_x + x > MAP_WIDTH - 1)
		return ;
	if (g_env.map->map[g_env.player_y + y][g_env.player_x + x].team)
		check_team(teams, g_env.map->map[g_env.player_y + y][g_env.player_x + x].team);
}

void		 check_la_vie_c_est_nul()
{
	int	teams[9];

	ft_memset(teams, 0, sizeof(teams));
	do_check(teams, -1, -1);
	do_check(teams, 0, -1);
	do_check(teams, 1, -1);
	do_check(teams, 1, 0);
	do_check(teams, 1, 1);
	do_check(teams, 0, 1);
	do_check(teams, -1, 1);
	do_check(teams, -1, 0);
}
