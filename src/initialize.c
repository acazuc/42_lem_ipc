#include "lem_ipc.h"

t_env	g_env;

static void	olalajesuisunmechansignal(int sig)
{
	(void)sig;
	ERROR("signal caught");
}

static void	olalajesuisunmechansignaldetypeinterrupt(int sig)
{
	(void)sig;
	ERROR("Interrupt");
}

static void	les_signaux_sont_desormais_tous_attrape()
{
	signal(SIGHUP, &olalajesuisunmechansignal);
	signal(SIGINT, &olalajesuisunmechansignaldetypeinterrupt);
	signal(SIGQUIT, &olalajesuisunmechansignal);
	signal(SIGILL, &olalajesuisunmechansignal);
	signal(SIGABRT, &olalajesuisunmechansignal);
	signal(SIGFPE, &olalajesuisunmechansignal);
	signal(SIGSEGV, &olalajesuisunmechansignal);
	signal(SIGPIPE, &olalajesuisunmechansignal);
	signal(SIGALRM, &olalajesuisunmechansignal);
	signal(SIGTERM, &olalajesuisunmechansignal);
	signal(SIGUSR1, &olalajesuisunmechansignal);
	signal(SIGUSR2, &olalajesuisunmechansignal);
	signal(SIGCHLD, &olalajesuisunmechansignal);
	signal(SIGBUS, &olalajesuisunmechansignal);
	signal(SIGPOLL, &olalajesuisunmechansignal);
	signal(SIGPROF, &olalajesuisunmechansignal);
	signal(SIGSYS, &olalajesuisunmechansignal);
	signal(SIGTRAP, &olalajesuisunmechansignal);
	signal(SIGVTALRM, &olalajesuisunmechansignal);
	signal(SIGXCPU, &olalajesuisunmechansignal);
	signal(SIGXFSZ, &olalajesuisunmechansignal);
}

void	initialize()
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
	les_signaux_sont_desormais_tous_attrape();
}
