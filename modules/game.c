//External dependencies
#include<unistd.h> //for sleep
#include<stdio.h> //for printf

//Internal dependencies
#include"headers.h"

void beginGame(int width, int height, int number_of_mines){
	printf(SEPARATION);

	coloredText("\nReady ?", 4);
	sleep(1);
	coloredText("\nSet...", 2);
	sleep(1);
	coloredText("\nGo !\n", 3);
	sleep(1);
	printf(SEPARATION"\n");

	//Ideally, if the game supported music, this would be where it'd start playing.

	
}