#include <stdio.h>
#include <stdlib.h>

#define CNT_DIGIT_ARRAY 10
#define GYSTO_SIZE_X 10
#define GYSTO_SIZE_Y 10

void printgysto_10_10_v(int * data);
void printgysto_10_10_g(int * data);

int main (int argc, char ** argv){
	int c, i, nwhite, nother;
	int ndigit[CNT_DIGIT_ARRAY];

	nwhite = nother = i = 0;

	for (i = 0; i < CNT_DIGIT_ARRAY; i++)
		ndigit[i] = 0;
	while ((c = getchar()) != EOF){
		if(c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}
	printf("digits =");
	for(i = 0; i < CNT_DIGIT_ARRAY; i++)
		printf(" %d:%d\t", i, ndigit[i]);
	printf("\n white space = %d, other = %d\n", nwhite, nother);


	printf("### #\n### #\n#####\n");
	printgysto_10_10_v(ndigit);
	printgysto_10_10_g(ndigit);
}

void printgysto_10_10_g(int * data){
	printf("%2c", ' ');
	for(int i = 0; i < GYSTO_SIZE_Y; i++)
		printf("%4d", i);
	for(int x = 0; x < GYSTO_SIZE_X; x++){
		for(int y = 0; y <= GYSTO_SIZE_Y; y++){
			if(y == 0)
				printf("\n%2d", x);
			else if(y <= data[x])
				printf("%4c", '#');
			else
				printf("%4c", ' ');
		}
	}
	printf("\n");
}


void printgysto_10_10_v(int * data){
	for(int y = 0; y < GYSTO_SIZE_Y; y++){
		printf("%2d", GYSTO_SIZE_Y - y);
		for (int x = 0; x < GYSTO_SIZE_X; x++){
			if(y >= (GYSTO_SIZE_Y - data[x]))
				printf("%4c", '#');
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	printf("  ");
	for(int i = 0; i < GYSTO_SIZE_X; i++)
		printf("%4d", i);
	printf("\n");
}
