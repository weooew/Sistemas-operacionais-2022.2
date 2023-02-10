#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
	int i, status;
	pid_t pid;
	
	if((pid = fork()) < 0){
		printf("Erro fork");
		exit(1);
	}
	
	if(pid == 0){
		printf("PID do filho: %d\n\n", getpid());
		for(i = 0; i < 3; i++){
			printf("%d\n", i);
			sleep(2);
		}
		_exit(0);
	}else{
		waitpid(pid, &status, 0);
		printf("PID do pai: %d\n\n", getpid());
	}
	
	scanf("%d", &i);
	return 0;
}

