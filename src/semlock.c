#include "lem_ipc.h"

t_env	g_env;

void	semlock()
{
	struct sembuf	semops[2];

	if (g_env.locked)
		return;
	semops[0].sem_num = 0;
	semops[0].sem_op = 0;
	semops[0].sem_flg = 0;
	semops[1].sem_num = 0;
	semops[1].sem_op = 1;
	semops[1].sem_flg = SEM_UNDO;
	if (semop(g_env.sem, semops, 2) == -1)
		ERROR("semop() failed (lock)");
	g_env.locked = 1;
}

void	semunlock()
{
	struct sembuf	semops[1];

	if (!g_env.locked)
		return;
	semops[0].sem_num = 0;
	semops[0].sem_op = -1;
	semops[0].sem_flg = 0;
	if (semop(g_env.sem, semops, 1) == -1)
		ERROR("semop() failed (unlock)");
	g_env.locked = 0;
}
