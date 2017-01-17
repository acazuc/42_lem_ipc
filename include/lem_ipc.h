#ifndef LEM_IPC_H
# define LEM_IPC_H

# include "../libft/include/libft.h"
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>

# define ERROR(x) (error_quit(x, __FILE__, __LINE__))

# define MAP_WIDTH 20
# define MAP_HEIGHT 20
# if MAP_WIDTH < 5
#  error Map width must be at least 5
# elif MAP_HEIGHT < 5
#  error Map height must be at least 5
# endif

typedef struct s_env	t_env;
typedef struct s_map	t_map;
typedef struct s_msg	t_msg;
typedef struct s_point	t_point;

void	error_quit(char *e, char *f, int l);
void	initialize();
void	semlock();
void	semunlock();
void	action();
void	display();
int	catch_enemy();
int	go_bottom();
int	go_top();
int	go_left();
int	go_right();
void	target_check();
void	target_find();
void	target_search();
void	target_send();
void	target_receive();
int	can_left();
int	can_right();
int	can_top();
int	can_bottom();
void	follow();
void	check_la_vie_c_est_nul();
void	cleanup();

struct		s_env
{
	char	*file;
	int	shm;
	int	sem;
	int	msgq;
	int	locked;
	int	player_x;
	int	player_y;
	int	player_id;
	int	target;
	int	target_x;
	int	target_y;
	char	team;
	t_map	*map;
};

struct		s_msg
{
	long	player;
	int	target;
};

struct		s_point
{
	int	team;
	int	player;
};

struct		s_map
{
	t_point	map[MAP_HEIGHT][MAP_WIDTH];
	int	players_count;
	int	total_players;
};

#endif
