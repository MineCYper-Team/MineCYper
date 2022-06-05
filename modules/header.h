#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define RELEASE_VERSION "1.0-dev"

//#define RESET_COLOR "\033[0m"
#define RESET_COLOR 0
#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define PURPLE 35
#define CYAN 36
#define WHITE 37

typedef struct{
	bool Flag;
	bool Revealed;
	int Value; //negative if mine, else bloc's value
} Bloc;

int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]);
void colorPrintf(char * Text, int Color);
int first_turn(int length, int height, Bloc** map, int mines);
void map_print(int length, int height, Bloc** map);
int reveal_bloc(int length, int height, Bloc** map, int abs, int ord, bool gameplay);
int turn(int length, int height, Bloc** map, int flags);
char* timeToClock(int seconds);
void full_reveal(int length, int height, Bloc** map);
bool winning(int length, int height, Bloc** map);

//Time saving system
int min(int a, int b);
void showBestTimes(char * fileName, int size);
void saveAndShowTime(int timeOnBeginning, char * fileName);
bool doesFileExist(char * fileName);
#define NORMAL_DIFFICULTY_SAVEDATA_LOCATION "normalDifficultyData.txt"
#define HARD_DIFFICULTY_SAVEDATA_LOCATION "hardDifficultyData.txt"
