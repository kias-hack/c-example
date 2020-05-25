#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 10000
#define NST 4.0 //count space chars for tab

int main(){
	printf("%c\n%d\n", '\a', '\a');
	char line[MAXLEN];
	int c, i, spacecnt;

	while((c = getchar()) != EOF && i < MAXLEN){
		if(c == ' ')
			spacecnt++;
		else if(spacecnt > 0){
			int tab, space;
			tab = spacecnt / NST;
			space = spacecnt - tab * NST;
			if((NST - space) == 1){
				space = 0;
				tab++;
			}
			while(tab-- > 0)
				line[i++] = '*';
			while((space--) > 0)
				line[i++] = '#';
			line[i++] = c;
			spacecnt = 0;
		}
		else
			line[i++] = c;
	}

	if(i > 0)
		printf("%s\n", line);

}
