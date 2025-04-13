#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>

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
    long nbr_philos;
    long time_for_eating;
    long time_for_thinking;
    long time_for_sleeping;
    long meals_limit;
    long start;
    bool end;
    my_fork *fork;
    my_philo *philo;
};



void error (char *str);

#endif