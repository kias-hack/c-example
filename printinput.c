#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc,char ** argv){
	char * str_help =
		"programm print every input symbol from keyboard"
		"Usage: pi [option] argument"
		"-o <filename> open or add new file and begin out char to file"
		"-h help\n";

	char * format = "ho:";
	char * filename = "";

	int opt;

	while((opt = getopt(argc, argv, format)) != -1){
		switch(opt){
			case ':': fprintf(stderr, "%s\n", "not enter argument for option");return 1;
			break;
			case '?': fprintf(stderr, "%s\n", "unknown option");return 1;
			break;
			case 'h' : fprintf(stderr, "%s\n", str_help);
			break;
			case 'o' : filename = optarg;
			break;
			default: fprintf(stderr ,"%s\n", "unknown error");return 1;
			break;
		}
	}

	if(filename != "")
		stdout = fopen(filename, "w+");

	int c, countchar = 0, countline = 0;

	short spaceflag = -1;

	printf("%d\n" ,EOF);

	while((c = getchar()) != EOF){
		if(c != 32 && spaceflag == 1)
			spaceflag =  -1;
		if(spaceflag == -1){
			countchar++;
			switch(c){
				case '\t' : printf("\\t");
				break;
				case '\b' : printf("\\b");
				break;
				case 92 : printf("\\\\");
				break;
				default: putchar(c);
				break;
			}
		}
		if(c == 32)
			spaceflag = 1;
		if(c == '\n')
			countline++;
	}
	printf("count chars - %d\ncount line %d\n", countchar, countline);
	if(filename != "")
		fclose(stdout);
	return 0;
}
