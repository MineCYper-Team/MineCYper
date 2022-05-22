//External Dependencies
#include<stdio.h> //for printf, scanf and getchar

//This function is a "wrapper" for scanf basically, it replaces integer scanf calls in other functions in order to prevent the user breaking the program.
int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]){
	int integer = minimum - 1;
	int type;

	while(integer<minimum || integer>maximum){
		type = scanf("%d", &integer);

		//Test if selection is an integer
		if(type!=1 && type!=2){
			printf(IntegerFailMessage);
			while(getchar()!='\n'); //This specific line prevents a glitch where scanf will be bypassed infinitely, softlocking the program.
		}

		//Test if selection is in the correct range
		else if(integer<minimum || integer>maximum){
			printf(RangeFailMessage);
		}
	}

	return integer;
}