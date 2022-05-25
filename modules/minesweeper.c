#include "header.h"

int menu(){ //main menu of the game
	int selection=0;
	//Regenerates the seed everytime the menu is loaded.
	int seed = rand();
	srand(seed);
	//Selection
	printf(" [1] Play\n [2] High Score\n [3] Credits\n [4] Exit\n\n\n");
	/*do{
		fflush(stdin);
		scanf("%c", &selection);
	}while(selection<'1' || selection>'4');*/
	selection = provideIntegerChoice(1, 4, "Please enter a value between 1 and 3", "Please enter a number");
	switch (selection){
	case 1:
		printf(" [1] Normal\n [2] Hard\n [3] Custom\n [4] Back\n\n\n");
		char selection_2[100]={};
		do{
			while(getchar()!='\n'); //flush
			scanf("%s", selection_2);
			if(selection_2[0]=='s' && selection_2[1]=='e' && selection_2[2]=='e' && selection_2[3]=='d'){
				printf("Please enter the seed\n");
				scanf("%d", &seed);
				srand(seed);
				printf("Seed: %d\n", seed);
			}
			//printf("Char 1: %c\nChar 2: %c\nChar 3: %c\nChar 4: %c\n", selection_2[0], selection_2[1], selection_2[2], selection_2[3]);
		}while(selection_2[0]<'1' || selection_2[0]>'4');
		printf("WIP\n");
		return menu();
		break;
	case 2:
		printf("WIP\n");
		return menu();
		break;
	case 3:
		printf("        ______      __  __   _          __     _______\n");					// ______      __  __   _          __     _______
		printf("        | ___ \\     | | | | | |         | |   (_) ___ \\\n");			// | ___ \     | | | | | |         | |   (_) ___ \ .
		printf("        | |_/ / __ _| |_| |_| | ___  ___| |__  _| |_/ /\n");				// | |_/ / __ _| |_| |_| | ___  ___| |__  _| |_/ /
		printf("        | ___ \\/ _` | __| __| |/ _ \\/ __| '_ \\| |  __/\n");			// | ___ \/ _` | __| __| |/ _ \/ __| '_ \| |  __/
		printf("        | |_/ / (_| | \\_| \\_| |  __/\\__ \\ | | | | |\n");				// | |_/ / (_| | \_| \_| |  __/\__ \ | | | | |
		printf("        \\____/ \\__,_|\\__|\\__|_|\\___\\/___/_| |_\\_\\_|\n\n");// \____/ \__,_|\__|\__|_|\___\/___/_| |_\_\_|
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
		printf("Oui je sais il est pas à jour je m'en occuperais plus tard\n\n");	//WIP
		return menu();
		break;
	case 4:
		return 0;
		break;
	default:
		printf("Error: switch default");
		return menu();
		break;
	}
}

int main(){
	//Generates a random seed
	srand(time(NULL));
	for(int i=0; i<20; i++){ //make rand more chaotic
		srand(rand());
	}
	char command[15];
	strcpy(command, "chcp 65001");
	system(command);
	printf("     ______      __  __   _          __     _______\n");         // ______      __  __   _          __     _______    // ______      __  __   _         __     _______
	printf("     | ___ \\     | | | | | |         | |   (_) ___ \\\n");      // | ___ \     | | | | | |         | |   (_) ___ \ . // | ___ \     | | | | | |        | |   (_) ___ \ .
	printf("     | |_/ / __ _| |_| |_| | ___  ___| |__  _| |_/ /\n");        // | |_/ / __ _| |_| |_| | ___  ___| |__  _| |_/ /   // | |_/ / __ _| |_| |_| | _______| |__  _| |_/ /
	printf("     | ___ \\/ _` | __| __| |/ _ \\/ __| '_ \\| |  __/\n");      // | ___ \/ _` | __| __| |/ _ \/ __| '_ \| |  __/    // | ___ \/ _` | __| __| |/ _ \ __| '_ \| |  __/
	printf("     | |_/ / (_| | \\_| \\_| |  __/\\__ \\ | | | | |\n");        // | |_/ / (_| | \_| \_| |  __/\__ \ | | | | |       // | |_/ / (_| | \_| \_| |  __/__ \ | | | | |
	printf("     \\____/ \\__,_|\\__|\\__|_|\\___\\/___/_| |_\\_\\_|\n\n\n");// \____/ \__,_|\__|\__|_|\___\/___/_| |_\_\_|       // \____/ \__,_|\__|\__|_|\___/___/_| |_\_\_|
	printf("Oui je sais il est pas à jour je m'en occuperais plus tard\n\n\n");	//WIP
	return menu();
}
