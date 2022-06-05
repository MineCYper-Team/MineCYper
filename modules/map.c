#include "header.h"

//This function will print a square depending on its data.
void bloc_print(Bloc bloc){
	if(bloc.Flag){
		colorPrintf("#",GREEN);
	}
	else if(bloc.Revealed){
		if(bloc.Value == -2){
			colorPrintf("*",RED);
		}
		else if(bloc.Value == -1){
			printf("*");
		}
		else if(bloc.Value == 0){
			printf("%d", bloc.Value);
		}
		else if(bloc.Value == 1){
			printf("\033[%dm%d\033[%dm", BLUE, bloc.Value, RESET_COLOR);	//Yellow
		}
		else if(bloc.Value == 2){
			printf("\033[%dm%d\033[%dm", CYAN, bloc.Value, RESET_COLOR);	//Red
		}
		else if(bloc.Value == 3){
			printf("\033[%dm%d\033[%dm", GREEN, bloc.Value, RESET_COLOR);	//Red
		}
		else if(bloc.Value == 4){
			printf("\033[%dm%d\033[%dm", YELLOW, bloc.Value, RESET_COLOR);	//Red
		}
		else if(bloc.Value == 5 || bloc.Value == 6){
			printf("\033[%dm%d\033[%dm", RED, bloc.Value, RESET_COLOR);	//Purple
		}
		else if(bloc.Value == 7 || bloc.Value == 8){
			printf("\033[%dm%d\033[%dm", PURPLE, bloc.Value, RESET_COLOR);	//Purple
		}
		else if(bloc.Value > 8){
			printf("?");	//Error
		}
	}
	else{
		printf(" ");
	}
}

//This function will print the grid.
void map_print(int length, int height, Bloc** map){
	//printf("Flags left: %d\n", flags_left);
	printf(" \\ ");
	for(int i = 0; i<length; i++){
		printf(" %c |", 'A'+i);
	}
	printf("\n  \\");
	for(int i = 0; i<length; i++){
		printf("___|");
	}
	for(int i = 0; i<height; i++){
		//printf("\n\n ligne n: %d\n\n", i);
		if(i<9){
			printf("\n %d| ", i+1);
		}
		else{
			printf("\n%d| ", i+1);
		}
		//printf("\n\n ligne n %d introduction finie\n\n", i);
		for(int j = 0; j<length; j++){
			bloc_print(map[j][i]);
			printf(" | ");
			//printf("\n\n ligne n %d colomne %d finie\n\n", i, j);
		}
		if(i+1 == height){
			printf("\n---");
			for(int j = 1; j<length; j++){
				printf("----");
			}
			printf("---/");
		}
		else{
			printf("\n--|");
			for(int j = 0; j<length; j++){
				printf("---|");
			}
		}
		//printf("\n\n ligne n %d finie\n\n", i);
	}
	printf("\n\n");
}
