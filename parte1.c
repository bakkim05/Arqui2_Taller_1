#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int end = 100;
int array1[99];
int array2[99];

int intToAscii(int number) {
    return '0' + number;
}

void *firstThread(void *vargp)
{
    int k = 0;
    while(k<end){
        array1[k]= rand()%256;
        k++;
        sleep(10/1000);
    }
    return NULL;
}

void *secondThread(void *vargp)
{
    int j = 0;
    while(j<end){
        array2[j]= rand()%256;
        j++;
        sleep(5/1000);
    }
    return NULL;
}

void *thirdThread(void *vargp)
{
    int p = 0;
    while(p<end){
        printf("array1[%d]: %d\n", p, array1[p]);
        printf("array2[%d]: %d\n", p, array2[p]);
        printf("XOR valor de array1 y array2: %c\n", intToAscii(array1[p]^array2[p]));
        p++;
        sleep(10/1000);
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    pthread_t thread_id[2];
    pthread_create(&thread_id[0], NULL, firstThread, NULL);
    pthread_create(&thread_id[1], NULL, secondThread, NULL);
    pthread_create(&thread_id[2], NULL, thirdThread, NULL);
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);
    pthread_join(thread_id[2], NULL);
    exit(0);
}