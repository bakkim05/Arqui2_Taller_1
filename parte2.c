#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int i = 0;
int end = 1000;

void *Thread(void *vargp)
{
    while (i < end){
        i++;
    }
    return NULL;
}


int main ()
{
    pthread_t thread_id[1];
    pthread_create(&thread_id[0], NULL, Thread, NULL);
    pthread_create(&thread_id[1], NULL, Thread, NULL);
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
}