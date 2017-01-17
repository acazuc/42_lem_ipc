#include "lem_ipc.h"

t_env	g_env;

static int	doneoui(int action)
{
	if (action == 0 && can_left())
		return (go_left());
	else if (action == 1 && can_right())
		return (go_right());
	else if (action == 2 && can_top())
		return (go_top());
	else if (action == 3 && can_bottom())
		return (go_bottom());
	return (0);
}

void		action()
{
	int	action;
	int	action_count;

	if (catch_enemy())
		return ;
	action = rand();
	action_count = 0;
	while (action_count < 4)
	{
		action %= 4;
		if (doneoui(action))
			return ;
		++action;
		++action_count;
	}
}
