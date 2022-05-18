// External Dependencies
#include<stdio.h> //for printf, scanf and getchar

// Internal Dependencies
#include"compiler.h"

//This function is for coloring
void color(int color){
	//The switch statement couldn't be used, sorry !
	if(color == 0){
		printf("\033[0m");			//Reset
	} else if (color == 1){
		printf("\033[30m");			//Black
	} else if (color == 2){
		printf("\033[31m");			//Red
	} else if (color == 3){
		printf("\033[32m");			//Green
	} else if (color == 4){
		printf("\033[33m");			//Yellow
	} else if (color == 5){
		printf("\033[34m");			//Blue
	} else if (color == 6){
		printf("\033[35m");			//Purple
	} else if (color == 7){
		printf("\033[36m");			//Cyan
	} else if (color == 8){
		printf("\033[37m");			//White
	}
}

void makeTitle(char * Title, int Color){
	color(Color);
	printf(SPACE);
	printf(Title);
	printf("\n");
	color(0);
}