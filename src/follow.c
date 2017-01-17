#include "lem_ipc.h"

t_env	g_env;

static void	get_move(int *move)
{
	int	lowest_move;

	lowest_move = 0;
	if (can_right() && g_env.player_x - g_env.target_x < -1)
		if (g_env.target_x - g_env.player_x > lowest_move)
		{
			lowest_move = g_env.target_x - g_env.player_x;
			*move = 1;
		}
	if (can_left() && g_env.player_x - g_env.target_x > 1)
		if (g_env.player_x - g_env.target_x > lowest_move)
		{
			lowest_move = g_env.player_x - g_env.target_x;
			*move = 2;
		}
	if (can_bottom() && g_env.player_y - g_env.target_y < -1)
		if (g_env.target_y - g_env.player_y > lowest_move)
		{
			lowest_move = g_env.target_y - g_env.player_y;
			*move = 3;
		}
	if (can_top() && g_env.player_y - g_env.target_y > 1)
		if (g_env.player_y - g_env.target_y > lowest_move)
		{
			lowest_move = g_env.player_y - g_env.target_y;
			*move = 4;
		}
}

void		follow()
{
	int	move;

	move = 0;
	get_move(&move);
	if (!move)
		return ;
	if (move == 1)
		go_right();
	else if (move == 2)
		go_left();
	else if (move == 3)
		go_bottom();
	else
		go_top();
}
