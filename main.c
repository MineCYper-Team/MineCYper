//External Dependencies
#include<unistd.h> //for sleep
#include<stdio.h> //for printf, scanf and getchar
#include<stdlib.h> //for waiting for user input

//Compiler directives
#define SEPARATION "------------------------------------------"
#define SPACE "\n       "

//This function is for coloring
void color(char *color){
	//The switch statement couldn't be used, sorry !
	if(color == "reset"){
		printf("\033[0m");
	} else if (color == "black"){
		printf("\033[30m");
	} else if (color == "red"){
		printf("\033[31m");
	} else if (color == "green"){
		printf("\033[32m");
	} else if (color == "yellow"){
		printf("\033[33m");
	} else if (color == "blue"){
		printf("\033[34m");
	} else if (color == "purple"){
		printf("\033[35m");
	} else if (color == "cyan"){
		printf("\033[36m");
	} else if (color == "white"){
		printf("\033[37m");
	}
}

//This function is a "wrapper" for scanf basically, it replaces integer scanf calls in other functions in order to prevent the user breaking the program.
int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]){
	int selection = minimum - 1;
	int type;

	while(selection<1 || selection>3){
		type = scanf("%d", &selection);

		//Test if selection is an integer
		if(type!=1 && type!=2){
			printf(IntegerFailMessage);
			while(getchar()!='\n');
		}

		//Test if selection is in the correct range
		else if(selection<1 || selection>3){
			printf(RangeFailMessage);
		}
	}
}

//This function simply show the difficulty selection menu.
void showDifficultySelectionMenu(){
	int selection;

	printf(SEPARATION);
	makeTitle("Choix de la difficulté","red");
	printf(SEPARATION);
	printf("\nVeuillez sélectionner une difficulté :\n");
	printf("1. Débutant (grille de 9x9 avec 10 mines)\n");
	printf("2. Intermédiaire (grille de 16x16 avec 40 mines)\n");
	printf("3. Difficile (grille de 30x16 avec 99 mines)\n");
	printf("4. Personalisé\n");
	printf("5. Retour au menu principal\n");
	printf("%s\n", SEPARATION);

	selection = provideIntegerChoice(1, 5, "\n... : ", "\n... : ");

	//Account for choice here
}

void showTutorial(){
	printf(SEPARATION);
	makeTitle("Tutoriel","green");
	printf(SEPARATION);
	printf("\nLe but du jeu est de découvrir toutes les cases sans activer de mine.\n");
	printf("Pour cela, vous devez cliquer sur une case.\n");
	printf("Si vous cliquez sur une case avec une mine, vous perdez.\n");
	printf("Si vous cliquez sur une case avec un chiffre, vous découvrez les cases adjacentes.\n");
	//Wait for user input
	printf("\nAppuyez sur une touche pour continuer...\n");
	system("read"); //Note : this works only on Linux, Windows will need "pause" instead
	showMainMenu();
}

void makeTitle(char * Title, char * Color){
	color(Color);
	printf(SPACE);
	printf(Title);
	printf("\n");
	color("reset");
}

//This function shows the main menu.
int showMainMenu(){
	//Main menu prints
	printf(SEPARATION);
	makeTitle("Menu Principal de MineCYper","blue");
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

int main(){
	printf("\nMineCYper v1.0, par Jordan et Eyal\n\n");

	sleep(3);

	return showMainMenu();
}