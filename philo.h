#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>

typedef struct container my_container;

typedef struct fork
{
    pthread_mutex_t fork;
    int id_fork;
}   my_fork;  


typedef struct philo
{
    int philo_id;
    long num_meals;
    bool done_eating;  
    long last_meal_time;
    my_fork *right_fork;
    my_fork *left_fork;
    my_container *container;
    pthread_t thread_id; // repersenting a philo by a thread 
}   my_philo;

struct container
{
    long num_of_philos;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long num_must_eat;
    long time_for_thinking;
    long start;
    bool end;
    my_fork *fork;
    my_philo *philo;
};



void error_message(char *str);
int parsing(my_container *container , char **argv);

#endif  
