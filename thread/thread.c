#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_1(void* p1);
void *thread_2(void*(*th)(unsigned int));

void *thread_1(void* p1) {
    sleep(2);
    printf("HEELO PRINTF");
    return ((void*)0);
}

void *thread_2(void*(*th)(unsigned int)) {
    sleep(2);
    printf("HEELO PRINTF 2");
    return ((void*)0);
}

int main(void) {

    pthread_t _t;
    printf("\nTHREAD BEFORE\n");
    pthread_create(&_t, 0, thread_2, 0);
    pthread_join(_t, 0);
    printf("\nTHREAD AFTER\n");

    printf("\nTHREAD BEFORE 1\n");
    pthread_create(&_t, 0, thread_1, 0);
    pthread_join(_t, 0);
    printf("\nTHREAD AFTER 1\n");
    return 0;
}