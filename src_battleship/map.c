#include "demineur.h"

void bloc_print(Bloc bloc){ //print a bloc depending on what it is
	if(bloc.Flag){
		printf("?");
	}
	else if(bloc.Revealed){
		if(bloc.Value == -2){
			printf("\033[31m*\033[0m"); //* in Red
		}
		else if(bloc.Value == -1){
			printf("*");
		}
		else if(bloc.Value == 0){
			printf("%d", bloc.Value);
		}
		else if(bloc.Value > 0 && bloc.Value < 4){
			printf("\033[33m%d\033[0m", bloc.Value);	//Yellow
		}
		else if(bloc.Value > 3 && bloc.Value < 7){
			printf("\033[31m%d\033[0m", bloc.Value);	//Red
		}
		else if(bloc.Value > 6 && bloc.Value < 9){
			printf("\033[35m%d\033[0m", bloc.Value);	//Purple
		}
		else if(bloc.Value > 8){
			printf("#");	//Error
		}
	}
	else{
		printf(" ");
	}
}

void map_print(int size, Bloc map[size][size], int flags_left){ //print the map
	printf("Flags left: %d\n \\ ", flags_left);
	for(int i = 0; i<taille; i++){
		printf("%c ", A+i);
	}
	printf("\n  \\");
	for(int i = 0; i<taille; i++){
		printf("__";
	}
	for(int i = 0; i<taille; i++){
		if(i<10){
			printf("\n %d| ", i+1);
		}
		else{
			printf("\n%d| ", i+1);
		}
		for(int j = 0; i<taille; i++){
			bloc_print(map[i][j]);
			printf(" | ");
		}
		printf("\n----");
		for(int j = 0; i<taille; i++){
			printf("----");
		}
	}
	printf("\n\n");
}
