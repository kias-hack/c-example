#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char ** argv){
	printf("size array %d \n", argc);
	for(int i = 0; i < argc; i++){
		printf(argv[i]);
		printf("\n");
	}

	for(int e = 1; e < argc; e++){
		for(int i = 0; i < strlen(argv[e]);i++){
			printf("%c", toupper(argv[e][i]));
		}
	}

	printf("\n");


	return 0;
}
