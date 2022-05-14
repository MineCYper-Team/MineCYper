#include<stdbool.h>
#define DIM 10
#define DEF_BOAT 20
#define DEF_BOAT_TYPE 8

void bloc(int bloc, char EmptyDefault, char BoatDefault, bool IsPlayer){ //print a bloc depending on its value
	if(bloc > 0 && IsPlayer){
		printf("\e[0;%dm%c\033[0m", 30+bloc, BoatDefault);	
	}
	else if(bloc >= 0){
		if(EmptyDefault=='1'){
			printf("\u25A1");
		}
		else{
			printf("%c", EmptyDefault);
		}
	}
	else if(bloc == -1){
		printf("O");
	}
	else if(bloc < -1 && IsPlayer){
		printf("\e[0;%dmX\033[0m", 29-bloc);
	}
	else if(bloc < -1){
		printf("X");
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