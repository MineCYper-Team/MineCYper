#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define RELEASE_VERSION "1.0-dev"

#define RESET_COLOR "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

typedef struct{
	bool Flag;
	bool Revealed;
	int Value; //negative if mine, else bloc's value
} Bloc;

int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]);
void colorPrintf(char * Text, char * Color);
