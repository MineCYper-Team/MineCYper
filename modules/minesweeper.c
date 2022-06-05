#include "header.h"

int showMainMenu(){ //main menu of the game
	int selection=0;

	//Regenerates the seed everytime the menu is loaded.
	int seed = rand();
	srand(seed);

	//Selection
	printf(" [1] Play\n [2] High Score\n [3] Credits\n [4] Exit\n\n\n");
	selection = provideIntegerChoice(1, 4, "Please enter a value between 1 and 4\n", "Please enter a number\n");

	switch (selection){
	case 1:;
		char selection_2[100]={};
		do{
			while(getchar()!='\n'); //flush
			printf(" [1] Normal\n [2] Hard\n [3] Custom\n [4] Back\n\n\n");
			scanf("%s", selection_2);
			if(selection_2[0]=='s' && selection_2[1]=='e' && selection_2[2]=='e' && selection_2[3]=='d'){
				printf("Please enter the seed\n");
				scanf("%d", &seed);
				srand(seed);
				printf("Seed : %d\n\n", seed);
			}
			//printf("Char 1: %c\nChar 2: %c\nChar 3: %c\nChar 4: %c\n", selection_2[0], selection_2[1], selection_2[2], selection_2[3]);
		}while(selection_2[0]<'1' || selection_2[0]>'4');
		/*int height;
		int length;
		int mines;*/
		int score;
		int selection_3 = atoi(&selection_2[0]);
		//printf("selec 2: %c\n", selection_2[0]);
		//printf("selec 3: %d\n\n", selection_3);

		int timer = time(NULL);

		switch (selection_3){
		case 1:;
			Bloc map_1[9][9]={};
			score = first_turn(9, 9, map_1, 10);

			timer = (time(NULL)-timer) * score;
			printf("Time : %d\n\n", timer);
			break;
		case 2:;
			Bloc map_2[16][16]={};
			score = first_turn(16, 16, map_2, 40);

			timer = (time(NULL)-timer) * score;
			printf("Time : %d\n\n", timer);
			break;
		case 3:;
			printf("Please enter the height of the grid\n");
			int height = provideIntegerChoice(4, 25, "Please enter a value between 4 and 25\n", "Please enter a number\n");
			printf("Please enter the length of the grid\n");
			int length = provideIntegerChoice(4, 25, "Please enter a value between 4 and 25\n", "Please enter a number\n");
			printf("Please enter the number of mines. This number cannot be greater than %d\n", ((height * length)-9)/2 );
			int mines = provideIntegerChoice(1, ((height * length)-9)/2, "Please enter a value between 1 and the number specified above\n", "Please enter a number\n");
			if(mines > ((height * length)-9)/2){
				colorPrintf("Error : This shouldn't happen. Returning to menu.\n\n",RED);
				return showMainMenu();
			}
			else{
				Bloc** map_3 = malloc(height * sizeof(Bloc*));
				for(int i = 0; i<height; i++){
					map_3[i] = malloc(length * sizeof(Bloc));
				}
				score = first_turn(length, height, map_3, mines);
				timer = (time(NULL)-timer) * score;
				printf("Time : %d\n\n", timer);
				for(int i = 0; i<height; i++){
					free(map_3[i]);
				}
				free(map_3);

			}
			//colorPrintf("WIP\n\n",YELLOW);
			//return showMainMenu();
			break;
		case 4:;
			return showMainMenu();
			break;
		default:;
			colorPrintf("Error : This shouldn't happen. Going back to the menu.\n\n",RED);
			return showMainMenu();
			break;
			//9x9 10; 16x16 40
		}
		/*Bloc map[length][height]={};
		map_print(length, height, map, mines);*/
		return showMainMenu();
		break;
	case 2:;
		printf("WIP\n");

		return showMainMenu();
		break;
	case 3:;
		printf("\n\n");
		printf("_|      _|  _|                        _|_|_|  _|      _|\n");
		printf("_|_|  _|_|      _|_|_|      _|_|    _|          _|  _|    _|_|_|      _|_|    _|  _|_|\n");
		printf("_|  _|  _|  _|  _|    _|  _|_|_|_|  _|            _|      _|    _|  _|_|_|_|  _|_|\n");
		printf("_|      _|  _|  _|    _|  _|        _|            _|      _|    _|  _|        _|\n");
		printf("_|      _|  _|  _|    _|    _|_|_|    _|_|_|      _|      _|_|_|      _|_|_|  _|\n");
		printf("							  _|\n");
		printf("							  _|\n");
		printf("\n");
		printf("       __  __         _       _          __   __   _    _\n");				//  __  __         _       _          __   __   _    _
		printf("      |  \\/  |__ _ __| |___  | |____  _  \\ \\ / /__(_)__| |\n");		// |  \/  |__ _ __| |___  | |____  _  \ \ / /__(_)__| |
		printf("      | |\\/| / _` | _` / -_) | '_ \\ \\| |  \\ V / _ \\ | _` |\n");	// | |\/| / _` | _` / -_) | '_ \ \| |  \ V / _ \ | _` |
		printf("      |_|  |_\\__,_|__,_\\___\\ |_.__/\\_, |   \\_/\\___/_|__,_|\n");	// |_|  |_\__,_|__,_\___\ |_.__/\_, |   \_/\___/_|__,_|
		printf("                                   |__/\n\n");											//                              |__/
		printf("__      ___ _   _      _   _          _        _             __\n");					// __      ___ _   _      _   _          _        _             __
		printf("\\ \\    / (_) |_| |_   | |_| |_  ___  | |_  ___| |_ __   ___ / _|\n");				// \ \    / (_) |_| |_   | |_| |_  ___  | |_  ___| |_ __   ___ / _|
		printf(" \\ \\/\\/ /| |  _| ' \\  |  _| ' \\/ -_) | ' \\/ -_) | '_ \\ / _ \\  _|\n");	//  \ \/\/ /| |  _| ' \  |  _| ' \/ -_) | ' \/ -_) | '_ \ / _ \  _|
		printf("  \\_/\\_/ |_|\\__|_||_|  \\__|_||_\\___| |_||_\\___|_| .__/ \\___/_|\n");		//   \_/\_/ |_|\__|_||_|  \__|_||_\___| |_||_\___|_| .__/ \___/_|
		printf("                                                |_|\n\n");									//                                                 |_|
		printf("       ____  _____   ____   __      ___ _ _             _\n");						// ____  _____   ____   __      ___ _ _             _
		printf("       | __| | __ \\ / ___|  \\ \\    / (_) | |__ _ _ ____| |\n");				// | __| | __ \ / ___|  \ \    / (_) | |__ _ _ ____| |
		printf("       | _/  | |/ / \\ \\___   \\ \\/\\/ /| | | / _` | '_/ _` |\n");			// | _/  | |/ / \ \___   \ \/\/ /| | | / _` | '_/ _` |
		printf("       \\_| O |___/O  \\___/O   \\_/\\_/ |_|_|_\\__,_|_| \\__,_|\n\n\n");	// \_| O |___/O  \___/O   \_/\_/ |_|_|_\__,_|_| \__,_|

		return showMainMenu();
		break;
	case 4:;
		colorPrintf("\nGoodbye\n",GREEN);
		return 0;
		break;
	default:;
		colorPrintf("Error : This shouldn't happen. Going back to the menu.\n\n",RED);
		return showMainMenu();
		break;
	}
}

int main(){
	//Generates a random seed
	srand(time(NULL));
	for(int i=0; i<20; i++){ //make rand more chaotic
		srand(rand());
	}

	//Windows compatibility
	#if defined(_WIN32) || defined(_CYGWIN)
	char command[15];
	strcpy(command, "chcp 65001");
	system(command);
	#endif

	//Print MineCYper Logo
	printf("\n\n");
	printf("_|      _|  _|                        _|_|_|  _|      _|\n");
	printf("_|_|  _|_|      _|_|_|      _|_|    _|          _|  _|    _|_|_|      _|_|    _|  _|_|\n");
	printf("_|  _|  _|  _|  _|    _|  _|_|_|_|  _|            _|      _|    _|  _|_|_|_|  _|_|\n");
	printf("_|      _|  _|  _|    _|  _|        _|            _|      _|    _|  _|        _|\n");
	printf("_|      _|  _|  _|    _|    _|_|_|    _|_|_|      _|      _|_|_|      _|_|_|  _|\n");
	printf("							  _|\n");
	printf("							  _|\n");
	printf("\n");

	return showMainMenu();
}
