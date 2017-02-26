/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 07:29:19 by acazuc            #+#    #+#             */
/*   Updated: 2017/02/26 07:42:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

t_env	g_env;

static void	olalajesuisunmechantsignal(int sig)
{
	(void)sig;
	ERROR("signal caught");
}

static void	olalajesuisunmechantsignaldetypeinterrupt(int sig)
{
	(void)sig;
	ERROR("Interrupt");
}

static void	les_signaux_sont_desormais_tous_attrape_pokemon(void)
{
	signal(SIGHUP, &olalajesuisunmechantsignal);
	signal(SIGINT, &olalajesuisunmechantsignaldetypeinterrupt);
	signal(SIGQUIT, &olalajesuisunmechantsignal);
	signal(SIGILL, &olalajesuisunmechantsignal);
	signal(SIGABRT, &olalajesuisunmechantsignal);
	signal(SIGFPE, &olalajesuisunmechantsignal);
	signal(SIGSEGV, &olalajesuisunmechantsignal);
	signal(SIGPIPE, &olalajesuisunmechantsignal);
	signal(SIGALRM, &olalajesuisunmechantsignal);
	signal(SIGTERM, &olalajesuisunmechantsignal);
	signal(SIGUSR1, &olalajesuisunmechantsignal);
	signal(SIGUSR2, &olalajesuisunmechantsignal);
	signal(SIGCHLD, &olalajesuisunmechantsignal);
	signal(SIGBUS, &olalajesuisunmechantsignal);
	signal(SIGPROF, &olalajesuisunmechantsignal);
	signal(SIGSYS, &olalajesuisunmechantsignal);
	signal(SIGTRAP, &olalajesuisunmechantsignal);
	signal(SIGVTALRM, &olalajesuisunmechantsignal);
	signal(SIGXCPU, &olalajesuisunmechantsignal);
	signal(SIGXFSZ, &olalajesuisunmechantsignal);
}

void		initialize(void)
{
	key_t	key;

	key = ftok(g_env.file, 8465132);
	if ((g_env.shm = shmget(key, sizeof(*g_env.map), IPC_CREAT | 0666)) == -1)
		ERROR("shmget() failed");
	if ((g_env.map = shmat(g_env.shm, NULL, 0)) == (void*)-1)
		ERROR("shmat() failed");
	if ((g_env.sem = semget(key, 1, IPC_CREAT | 0666)) == -1)
		ERROR("semget() failed");
	if ((g_env.msgq = msgget(key, IPC_CREAT | 0666)) == -1)
		ERROR("msgget failed");
	les_signaux_sont_desormais_tous_attrape_pokemon();
}
