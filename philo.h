#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>



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
    bool is_dead;
    bool done_eating; 
    long start;
    mutex *fork;
    t_mutex *mutexes;
    t_philo *philo;
};


void init_container(t_container *my_container);
void error_message(char *str);
int parsing(t_container *container, char **argv);

void having_seats(t_container *my_container);
void dinner(t_container *container);
void doing_dishes(t_container *container);

void my_usleep(long time);
void printing(t_philo *philo, char *str);
void *allocate(size_t size, t_container *container);
long gettime(void);
void get_forks (t_philo *philo, t_container *container, int position);

void eat(t_philo *philo);
void s_leep(t_philo *philo);
void think(t_philo *philo);

int checks(t_container *container);
int dead(t_container *container);
int done_eating(t_container *container);

void *monitor (void *ptr);

#endif  
