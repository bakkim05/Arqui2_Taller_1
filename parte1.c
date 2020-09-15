#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int array1[0];
int array2[0];

int intToAscii(int number) {
    return '0' + number;
}

void *firstThread(void *vargp)
{
    srand(time(0)+10);
    sleep(10/1000);
    array1[0]= rand()%256;
    printf("array1: %d\n",array1[0]);
    return NULL;
}

void *secondThread(void *vargp)
{
    srand(time(0));
    sleep(5/1000);
    array2[0]= rand()%256;
    printf("array2: %d\n",array2[0]);
    return NULL;
}

int main()
{
    
    pthread_t thread_id;
    for (int i=0; i<10; i++){
        pthread_create(&thread_id, NULL, firstThread, NULL);
        pthread_create(&thread_id, NULL, secondThread, NULL);
        pthread_join(thread_id, NULL);
        printf("valor final array1: %d\n",array1[0]);
        printf("valor final array2: %d\n",array2[0]);
        printf("XOR del array1 y array2: %c\n", intToAscii(array1[0]^array2[0]));
    }
    exit(0);
}
