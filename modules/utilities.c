#include "headers.h"

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
			while(getchar()!='\n');
		}

		//Test if selection is in the correct range
		else if(integer<minimum || integer>maximum){
			printf("%s", RangeFailMessage);
		}
	}

	return integer;
}
