#include <stdio.h>

#define NST 4 //count space key for tab
#define MAXLEN 10000

int main (){
	int c, tab = 0, i = 0;
	char line[MAXLEN];

	while((c = getchar()) != EOF){
		if(c == '\t')
			tab++;
		else if(tab > 0){
			int nextpoint = i + tab * NST;
			while(i < nextpoint)
				line[i++] = ' ';
			tab = 0;
		}
		else
			line[i++] = c;
	}
	if(i > 0)
		printf("%s\n", line);
}
