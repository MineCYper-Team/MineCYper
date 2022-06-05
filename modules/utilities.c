#include "header.h"

int max_(int a, int b){ //take the greater of two
	if(a>b){
		return a;
	}
	return b;
}

int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]){
	int integer = minimum - 1;
	int type;

	while(integer<minimum || integer>maximum){
		type = scanf("%d", &integer);

		//Test if selection is an integer
		if(type!=1 && type!=2){
			printf("%s", IntegerFailMessage);
			while(getchar()!='\n'); //This specific line prevents a glitch where scanf will be bypassed infinitely, softlocking the program.
		}

		//Test if selection is in the correct range
		else if(integer<minimum || integer>maximum){
			printf("%s", RangeFailMessage);
		}
	}

	return integer;
}

//Colored Text
void colorPrintf(char * Text, int Color){
	printf("\033[%dm%s\033[0m", Color, Text);
	/*printf("\033[%dm", Color);
	printf("%s", Text);
	printf("\033[0m");*/
}

//Convert seconds time to clock format
char * timeToClock(int seconds){
	int hours = seconds/3600;
	int minutes = (seconds%3600)/60;
	int seconds_ = seconds%60;

	char * clock = malloc(sizeof(char)*8);
	sprintf(clock, "%02d:%02d:%02d", hours, minutes, seconds_);

	return clock;
}

int min(int a, int b){
	if(a<b){
		return a;
	}
	return b;
}