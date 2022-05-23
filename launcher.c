//External Dependencies
#include<stdio.h> //for printf
#include<unistd.h> //for sleep
#include<stdlib.h> //for rand
#include<time.h> //for time

//Internal Dependencies
#include"modules/headers.h"

int main(){
	printf("\nMineCYper v");
	printf(RELEASE_VERSION);
	printf(", par Jordan et Eyal\n\n");

	//Easter egg
	srand(time(NULL));
	if (rand() % 101 > 80){
		sleep(2);
		color(4);printf("Jordan : ");color(0);
		printf("Qu'est-ce qu'il y a, Eyal ?\n");
		sleep(2);
		color(4);printf("Jordan : ");color(0);
		printf("Ouais, mais je crois pas qu'ils vont avoir la référence...\n");
		sleep(2);
		color(4);printf("Jordan : ");color(0);
		printf("OK ! OK ! OK ! Si t'insistes...\n");
		sleep(2);
		color(4);printf("Jordan : ");color(0);
		printf("Crédits à F.D.C. Willard... C'est le chat d'un scientifique pour information...\n");
		sleep(2);
		color(4);printf("Jordan : ");color(0);
		printf("Bon ! Sur ce, bon jeu.\n\n");
	}
	
	sleep(3);
	
	return showMainMenu();
}