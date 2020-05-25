#include <stdio.h>

#define MAXLENLINE 10

int mygetline(char s[], int lim);
void linecopy(char to[], char from[]);

int main (){
	int c, max, len;
	char line[MAXLENLINE];
	char longest[MAXLENLINE];
	max = 0;
	while((len = mygetline(line, MAXLENLINE)) > 0){
		if(len > max){
			max = len;
			linecopy(longest, line);
		}
	}
	if(max > 0)
		printf("max line %s\n", longest);
	return 0;
}

int mygetline(char s[], int lim){
	int c,i;
	for(i = 0; i < lim-2 && (c = getchar()) != '\n' && c != EOF;i++)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;

}

void linecopy(char to[], char from[]){
	int i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
