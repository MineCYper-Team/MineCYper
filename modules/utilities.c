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

//This function is for coloring
void color(int color){
	switch(color){
	case 0:
		printf("\033[0m");			//Reset
		break;
	case 1:
		printf("\033[30m");			//Black
		break;
	case 2:
		printf("\033[31m");			//Red
		break;
	case 3:
		printf("\033[32m");			//Green
		break;
	case 4:
		printf("\033[33m");			//Yellow
		break;
	case 5:
		printf("\033[34m");			//Blue
		break;
	case 6:
		printf("\033[35m");			//Purple
		break;
	case 7:
		printf("\033[36m");			//Cyan
		break;
	case 8:
		printf("\033[37m");			//White
		break;
	}
}

//Colored Text
void coloredText(char * Text, int Color){
	color(Color);
	printf("%s", Text);
	color(0);
}