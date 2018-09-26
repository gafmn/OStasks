#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h>

int main(){
	int readWrite[2];

	char str[] = "OS";
	char res[] = "";
	pid_t pipe;

	if (pipe(readWrite) == -1){
		printf("%s","Pipe failed");
		return 1;
	} 

	write(readWrite[1], str, strlen(str) + 1);
	close(readWrite[1]);
	read(readWrite[0], res, strlen(str) + 1);
	close(readWrite[0]);

	return 0;
}