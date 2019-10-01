#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int value = 0;
void * fib(void * param){
	value = 5;
	pthread_exit(0);
}
int main(int argc, char const *argv[])
{
	pthread_t thread;
	if(fork()==0){
		pthread_create(&thread,0,fib,NULL);
		pthread_join(thread,NULL);
		printf("%d\n",value);
	}
	else{
		wait(NULL);
		printf("%d\n",value);
	}
	return 0;
}