#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_t thread_id[1];
pthread_mutex_t lock;
int process;

void *Thread(void *vargp)
{
    pthread_mutex_lock(&lock);
    process += 1;
    
    printf("Proceso %d iniciado\n", process);
    for (int i=0; i < 100 ; i++){
        //does nothing
    }
    printf("Proceso %d terminado\n", process);

    pthread_mutex_unlock(&lock);

    return NULL;
}


int main ()
{
    pthread_mutex_init(&lock,NULL);
    pthread_create(&thread_id[0], NULL, Thread, NULL);
    pthread_create(&thread_id[1], NULL, Thread, NULL);
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    pthread_mutex_destroy(&lock); 
}