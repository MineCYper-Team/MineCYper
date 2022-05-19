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
			printf("*")
		}
		else if(bloc.Value == 0){
			printf("%d", bloc.Value)
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

void map_print_1p(int map[DIM][DIM], int score){ //print the map
	printf("Score: %d\n \\ A B C D E F G H I J\n  \\___________________", score);
	for(int value1 = 0; value1 < DIM; value1++){
		if(value1<DIM-1){
			printf("\n %d|", value1 + 1);
		}
		else{
			printf("\n%d|", value1 + 1);
		}
		for(int value2 = 0; value2 < DIM; value2++){
			bloc(map[value2][value1], ' ', '@', 1);
			printf(" ");
		}
	}
	printf("\n\n");
}
