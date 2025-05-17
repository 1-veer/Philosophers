#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>



typedef struct s_container t_container;
typedef pthread_mutex_t mutex;


typedef struct s_mtx
{
	mutex	*print_mtx;
	mutex	*time_mtx;
	mutex	*meals_mtx;
	mutex	*dead_mtx;
	mutex	*done_mtx;
}	t_mutex;

typedef struct s_philo
{
    t_container *container;
    int philo_id;
    pthread_t thread_id; // repersenting a philo by a thread 
    long meal_counter;
    long last_meal_time;
    mutex *right_fork;
    mutex *left_fork;
}   t_philo;

struct s_container
{
    long num_of_philos;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long num_must_eat;
    bool dead;
    bool done_eating;
    long start;
    mutex *fork;
    t_mutex *mutex;
    t_philo *philo;
};


void init_container(t_container *my_container);
void error_message(char *str);
int parsing(t_container *container, char **argv);

#endif  
