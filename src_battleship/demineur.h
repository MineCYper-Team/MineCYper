#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef struct{
	bool Flag;
	bool Revealed;
	int Value; //negative if mine, else bloc's value
} Bloc;
