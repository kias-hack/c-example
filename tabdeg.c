#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

#define INIT_PARAM -1

float ctof();
float ftoc();

int main (int argc,char ** argv){
	int opt;
	int lower = INIT_PARAM, max = INIT_PARAM, step = INIT_PARAM;
	char mode = 'c';
	float celsius, fahrengate;
	char * str_help = "Usage: tabdeg [PARAMS] \n"
	     	     "-l <lower value> to point a lower value fahrengate \n"
		     "-u <maximum value> to point a max value fahrengate  \n"
		     "-s <step> step value\n"
		     "-f -c point to mode (c - f to c) (f - c to f)\n";

	while((opt = getopt(argc, argv, "fcl:u:s:")) != -1){
		switch(opt){
			case 'l': lower = atoi(optarg);
			break;
			case 'f': mode = 'f';
			break;
			case 'c': mode = 'c';
			break;
			case 'u': max = atoi(optarg);
			break;
			case ':': fprintf(stderr, "%s", str_help);
				  return 1;
			break;
			case '?': fprintf(stderr, "%s", str_help);
				  return 1;
			break;
			case 's': step = atoi(optarg);
			break;
			default: fprintf(stderr, "%s", "unknown error\n", opterr);
			break;
		}
	}

	if(lower == -1 || max == -1 || step == -1){
		fprintf(stderr, "%s",str_help);
		fprintf(stderr, "%s", "empty params \n");
		return 1;
	}

	printf("%7s\t%10s\n", "celsius", "fahrengate");

	if(mode == 'c'){
		fahrengate = lower;
		while (fahrengate <= max){
			celsius = ftoc(fahrengate);
			printf("%7.1f \t %10.1f\n", celsius, fahrengate);
			fahrengate += step;
		}
	}
	else{
		celsius = lower;
		while (celsius <= max){
			fahrengate = ctof(celsius);
			printf("%7.1f\t%10.1f\n", celsius, fahrengate);
			celsius += step;
		}
	}
	return 1;
}

float ctof(celsius)
float celsius;
{
	return (celsius * 9.0/ 6.0) + 32;
}

float ftoc(fahrengate)
float fahrengate;
{
	return 5.0 * (fahrengate - 32.0) / 9.0;
}
