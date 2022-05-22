// External Dependencies
#include<stdio.h> //for printf, scanf and getchar

// Internal Dependencies
#include"compiler.h"

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

//Allows us to easily make titles in menus
void makeTitle(char * Title, int Color){
	color(Color);
	printf(SPACE);
	printf(Title);
	printf("\n");
	color(0);
}