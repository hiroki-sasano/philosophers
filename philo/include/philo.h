#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_rules
{
	int				n_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				must_eat;
	long			start_time;
	int				stop;
	pthread_mutex_t	print_m;
	pthread_mutex_t	stop_m;
	pthread_mutex_t	*forks;
}					t_rules;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t meal_m;
	t_rules			*rules;
}					t_philo;

/* parse.c */
int					parse_args(t_rules *r, int ac, char **av);

/* init.c / destroy.c */
int					init_all(t_rules *r, t_philo **philos);
void				destroy_all(t_rules *r, t_philo *philos);

/* time.c */
long				now_ms(void);
long				elapsed_ms(long start_ms);
void				smart_usleep(long ms, t_rules *rules);

/* print.c*/
void	print_state(t_philo *p, char *msg);

/* thread.c*/
int		create_threads(int n, t_philo	*p);
void		join_threads(int n_philo, t_philo *philos);

/* routine.c*/
void	*philo_routine(void *arg);

/* fork.c */
void	take_forks(t_philo *p);
void 	put_forks(t_philo *p);

/*actions.c*/
void	eat(t_philo *p);
void	philo_sleep(t_philo *p);
void	think(t_philo *p);

/* stop_utils.c */
int 	get_stop(t_rules *r);
void	set_stop(t_rules *r, int value);

/* utils.c */
int		ft_atoi_pos(const char *s, int *out);
// int		ft_strcmp(const char *s1, const char *s2);
void	put_err(const char *s);

/* monitor.c */
void	*monitor_routine(void *arg);

#endif

// lock order: stop_m → print_m → meal_m


/*
n_philo     哲学者の人数（＝forkの数）
t_die / t_eat / t_sleep 引数で指定される時間
must_eat    全員がこれだけ食べたら終了（optional）
start_time  シミュレーション開始時刻
stop        シミュレーション終了フラグ
print       ログ出力専用 mutex
stop_m      stop を守る mutex
*/

/*
pthread_mutex_t m; mutex作成
pthread_mutex_init(&m, NULL);初期化
pthread_mutex_lock(&m);
pthread_mutex_unlock(&m);
pthread_mutex_destroy(&m);
*/

/*
mutexの入れ物用意
pthread_mutex_t		forks[n_philo];

mutex初期化
for					(i = 0; i < n; i++)
	pthread_mutex_init(&forks[i], NULL);
*/

/*
philo[i].left_fork  = &forks[i];
philo[i].right_fork = &forks[(i + 1) % n_philo];
*/

/*
id          哲学者番号（1〜n）
eat_count   今まで食べた回数
last_meal   最後に食べ始めた時刻
thread      この哲学者のスレッド
left_fork   fork mutex へのポインタ
right_fork  fork mutex へのポインタ
rules       全体ルールへの参照
*/