#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define RELEASE_VERSION "1.0-dev"

typedef struct{
	bool Flag;
	bool Revealed;
	int Value; //negative if mine, else bloc's value
} Bloc;

int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]);
void color(int color);
void coloredText(char * Text, int Color);