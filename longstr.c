#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10000
#define MAXLINES 100
#define MAXRECORD 10

int mygetline(char *line, int lim);
void reverse(char *line, int len);


int main(){
	char line[MAXLEN];
	char maxlines[MAXLINES][MAXLEN];
	int max, len;

	max = len = 0;

	while((len = mygetline(line, MAXLEN)) > 0){
		if(len >= MAXRECORD && max < MAXLINES){
			int i = 0;
			while((maxlines[max][i] = line[i]) != '\0')
				++i;
			++max;
		}
	}
	printf("\n\n maximale length string: \n");
	while(max > 0){
		--max;
		printf("%s", maxlines[max]);
	}
}

void reverse(char * line, int len){
	char dline[MAXLEN];
	int i, end;
	
	while(line[i] != '\n'){
		dline[i] = line[i];
		++i;
	}
	i = end = --i;
	while(i >= 0){
		line[i] = dline[end-i];
		--i;
	}
}

int mygetline(char *line, int lim){
	int i = 0, c, bag = 0;

	while((c = getchar()) && c != EOF && c != '\n' && i < (lim-2)){
		if(c == '\t' || c == ' ')
			bag = c;
		else if(bag > 0 && c != '\n'){
			bag = 0;
			line[i++] = c;
		}
		else if(bag == 0)
			line[i++] = c;
	}
	if(c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	if(i >= 3)
		reverse(line, i);
	printf("%s",line);
	return i;
}
