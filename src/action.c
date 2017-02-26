/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 07:28:47 by acazuc            #+#    #+#             */
/*   Updated: 2017/02/26 07:43:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_env	g_env;

static int	doneoui(int action)
{
	if (action == 0 && can_left())
		go_left();
	else if (action == 1 && can_right())
		go_right();
	else if (action == 2 && can_top())
		go_top();
	else if (action == 3 && can_bottom())
		go_bottom();
	else
		return (0);
	return (1);
}

void		action(void)
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
