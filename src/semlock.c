/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semlock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 07:29:32 by acazuc            #+#    #+#             */
/*   Updated: 2017/02/26 07:36:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_env	g_env;

void	semlock(void)
{
	struct sembuf	semops[2];

	if (g_env.locked)
		return ;
	semops[0].sem_num = 0;
	semops[0].sem_op = 0;
	semops[0].sem_flg = 0;
	semops[1].sem_num = 0;
	semops[1].sem_op = 1;
	semops[1].sem_flg = 0;
	if (semop(g_env.sem, semops, 2) == -1)
		ERROR("semop() failed (lock)");
	g_env.locked = 1;
}

void	semunlock(void)
{
	struct sembuf	semops[1];

	if (!g_env.locked)
		return ;
	semops[0].sem_num = 0;
	semops[0].sem_op = -1;
	semops[0].sem_flg = 0;
	if (semop(g_env.sem, semops, 1) == -1)
		ERROR("semop() failed (unlock)");
	g_env.locked = 0;
}
