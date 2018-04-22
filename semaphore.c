#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
void *fun1();
void *fun2();
int shared=1;
sem_t s;
int main()
{
sem_init(&s,0,1);
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("Final Value of shared is %d\n",shared);
}

void *fun1()
{
int x;
sem_wait(&s);
x=shared;
x++;
sleep(1);
shared=x;
sem_post(&s);
}
void *fun2()
{
int x;
sem_wait(&s);
x=shared;
x--;
sleep(1);
shared=x;
sem_wait(&s);
}