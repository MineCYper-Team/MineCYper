//External Dependencies
#include<stdio.h> //for printf
#include<unistd.h> //for sleep

//Internal Dependencies
#include"modules/menus.h"

int main(){
	printf("\nMineCYper v1.0, par Jordan et Eyal\n\n");

	sleep(3);

	return showMainMenu();
}