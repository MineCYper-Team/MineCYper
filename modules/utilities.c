#include "headers.h"

int max(int a, int b){
	/* if(a>b){
		return a;
	}
	return b; */

	/* Optimized alternative found online. We must remember to be careful when we use if statements in function that are used repeatedly.*/
	return a ^ ((a ^ b) & -(a < b));
}


int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]){
	int integer = minimum - 1;
	int type;

	while(integer<minimum || integer>maximum){
		type = scanf("%d", &integer);

		//Test if selection is an integer
		if(type!=1 && type!=2){
			printf(IntegerFailMessage);
			while(getchar()!='\n');
		}

		//Test if selection is in the correct range
		else if(integer<minimum || integer>maximum){
			printf(RangeFailMessage);
		}
	}

	return integer;
}
