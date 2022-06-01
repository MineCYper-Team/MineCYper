#include "header.h"

void bloc_print(Bloc bloc){ //print a bloc depending on what it is
	if(bloc.Flag){
		printf("?");
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
		else if(bloc.Value > 0 && bloc.Value < 4){
			printf("\033[%dm%d\033[%dm", YELLOW, bloc.Value, RESET_COLOR);	//Yellow
		}
		else if(bloc.Value > 3 && bloc.Value < 7){
			printf("\033[%dm%d\033[%dm", RED, bloc.Value, RESET_COLOR);	//Red
		}
		else if(bloc.Value > 6 && bloc.Value < 9){
			printf("\033[%dm%d\033[%dm", PURPLE, bloc.Value, RESET_COLOR);	//Purple
		}
		else if(bloc.Value > 8){
			printf("#");	//Error
		}
	}
	else{
		printf(" ");
	}
}

void map_print(int length, int height, Bloc map[length][height], int flags_left){ //print the map
	printf("Flags left: %d\n \\ ", flags_left);
	for(int i = 0; i<length; i++){
		printf("%c ", 'A'+i);
	}
	printf("\n  \\");
	for(int i = 0; i<length; i++){
		printf("__");
	}
	for(int i = 0; i<height; i++){
		if(i<10){
			printf("\n %d| ", i+1);
		}
		else{
			printf("\n%d| ", i+1);
		}
		for(int j = 0; i<length; i++){
			bloc_print(map[i][j]);
			printf(" | ");
		}
		printf("\n----");
		for(int j = 0; i<length; i++){
			printf("----");
		}
	}
	printf("\n\n");
}
