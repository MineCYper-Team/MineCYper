// External Dependencies
#include<stdio.h> //for printf, scanf and getchar
#include<unistd.h> //for sleep
#include<stdlib.h> //for waiting for user input

// Internal Dependencies
#include"compiler.h"
#include"design.h"
#include"utilities.h"
#include"menus.h" //Prevents a warning

//This function simply show the difficulty selection menu.

void showDifficultySelectionMenu(){
	printf(SEPARATION);
	makeTitle("Choix de la difficulté",2);
	printf(SEPARATION);
	printf("\nVeuillez sélectionner une difficulté :\n");
	printf("1. Débutant (grille de 9x9 avec 10 mines)\n");
	printf("2. Intermédiaire (grille de 16x16 avec 40 mines)\n");
	printf("3. Difficile (grille de 30x16 avec 99 mines)\n");
	printf("4. Personalisé\n");
	printf("5. Retour au menu principal\n");
	printf(SEPARATION);

	printf("\nVeuillez choisir une option : ");
	int selection_difficulte = provideIntegerChoice(1, 5, "\nErreur d'intervalle : ","\nErreur d'entier : ");

	switch (selection_difficulte){
	case 1:
		//beginGame(9, 9, 10);
		break;
	case 2:
		//beginGame(16, 16, 40);
		break;
	case 3:
		//beginGame(30, 16, 99);
		break;
	case 4:
		//showConfigMenu();
		break;
	case 5:
		showMainMenu();
		break;
	}
}

void showTutorial(){
	printf(SEPARATION);
	makeTitle("Tutoriel",3);
	printf(SEPARATION);
	printf("\nLe but du jeu est de découvrir toutes les cases sans activer de mine.\n");
	sleep(TUTORIAL_WAIT_TIME);
	printf("Pour cela, vous devez cliquer sur une case.\n");
	sleep(TUTORIAL_WAIT_TIME);
	printf("Si vous cliquez sur une case avec une mine, vous perdez.\n");
	sleep(TUTORIAL_WAIT_TIME);
	printf("Si vous cliquez sur une autre case, vous découvrez son chiffre.\n");
	sleep(TUTORIAL_WAIT_TIME);
	printf("Ce chiffre indique le nombre de mines à proximité.\n");
	sleep(TUTORIAL_WAIT_TIME);
	printf("Si le chiffre est 0, les cases directement connectées seront révélées, ainsi que les cases qui leur sont connectées (sauf si le chiffre des cases connectées n'est pas 0.) \n");
	sleep(TUTORIAL_WAIT_TIME);
	//Wait for user input
	printf("\nAppuyez sur Entrée pour continuer...\n");
	system("read"); //Note : this works only on Linux, Windows will need "pause" instead
	showMainMenu();
}

//This function shows the main menu.
int showMainMenu(){
	//Main menu prints
	printf(SEPARATION);
	makeTitle("Menu Principal de MineCYper",5);
	printf(SEPARATION);
	printf("\n1. Démarrer le jeu\n");
	printf("2. Démarrer le tutoriel\n");
	printf("3. Quitter\n");
	printf(SEPARATION);
	printf("\nVeuillez choisir une option: ");

	int mode_selection = provideIntegerChoice(1,3,"\nEuh... : ","\nC'est-à-dire un nombre entier... : ");

	switch (mode_selection){
	case 1:
		//Show the difficulty selection menu
		showDifficultySelectionMenu();
		break;
	case 2:
		//Launch tutorial
		showTutorial();
		break;
	case 3:
		//Quit
		printf(SEPARATION);
		printf("\nMerci d'avoir joué !\n");
		printf(SEPARATION);
		printf("\n");
		return 0;
	}
}