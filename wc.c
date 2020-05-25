#include <stdio.h>

#define IN   1
#define OUT  0
#define CHAR 2

int ischar(int c);


int main(int argc, char * argv){
	int state, nc, nl, nw, c, ischf;

	nc = nl = nw = ischf = 0;
	state = OUT;

	while((c = getchar()) !=  EOF){
		nc++;
		printf("input %d is char %d\n", c, ischf);
		if(c == '\n')
			nl++;
		else if(c == '\t' || c == ' ' || c == '\n')
			state = OUT;
		else if(state == OUT && ischf == 1){
			state = IN;
			nw++;
		}
		else if(state == IN && ischf == 0){
			nw--;
			state = OUT;
		}
		else if(ischf == 0)
			state = CHAR;
		//if(state == IN)
		//	putchar(c);
	}
	printf("nc = %d\nnl = %d\nnw = %d\n", nc, nl, nw);
}


int ischar(int c){
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return 1;
	return 0;
}
