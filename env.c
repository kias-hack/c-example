#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char ** argv){
	if(argc < 3){
		fprintf(stderr, "Need 3 arguments/n");
		return 1;
	}
	if(argc > 3){
		if(setenv(argv[1], argv[2], atoi(argv[3])) < 0){
			fprintf(stderr, "Not perezapis\n");
			return 1;
		}
	}
	else{
		if(setenv(argv[1], argv[2], 0) < 0){
			fprintf(stderr, "Not variable\n");
			return 1;
		}
	}

	printf("Variable %s=%s \n", argv[1], getenv(argv[1]));
	
	if(unsetenv(argv[1]) < 0){
		fprintf(stderr, "I do not unseting variable\n");
	}
	
	printf("Variable %s=%s \n", argv[1], getenv(argv[1]));




	return 0;
}
