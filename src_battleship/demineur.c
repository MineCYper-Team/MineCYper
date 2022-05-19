#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef struct{
	bool Mine;
	bool Flag;
	bool Revealed;
	char Symbol;
	int color;
} Square;

int max_(int a, int b){ //take the greater of two
	if(a>b){
		return a;
	}
	return b;
}

int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]){
	int integer = minimum - 1;
	int type;

	while(integer<minimum || integer>maximum){
		type = scanf("%d", &integer);

		//Test if selection is an integer
		if(type!=1 && type!=2){
			printf(IntegerFailMessage);
			while(getchar()!='\n');
		}

		//Test if selection is in the correct range
		else if(integer<minimum || integer>maximum){
			printf(RangeFailMessage);
		}
	}

	return integer;
}

int menu(){ //main menu of the game
	int x=0;
	int seed = rand();
	srand(seed);
	printf(" [1] Play\n [2] Credits\n [3] Exit\n\n\n");
	/*do{
		fflush(stdin);
		scanf("%c", &x);
	}while(x<'1' || x>'4');*/
	x = provideIntegerChoice(1, 3, "Please enter a value between 1 and 3", "Please enter a number");
	if(x==1){
		printf(" [1] Normal\n [2] Hard\n [3] Custom\n [4] Back\n\n\n");
		char y[100]={};
		do{
			fflush(stdin);
			scanf("%s", y);
			if(y[0]=='s' && y[1]=='e' && y[2]=='e' && y[3]=='d'){
				printf("Please enter the seed\n");
				scanf("%d", &seed);
				srand(seed);
				printf("Seed: %d\n", seed);
			}
			//printf("Char 1: %c\nChar 2: %c\nChar 3: %c\nChar 4: %c\n", y[0], y[1], y[2], y[3]);
		}while(y[0]<'1' || y[0]>'4');
		printf("WIP");
		return menu();
	}
	else if(x==2){
		printf("        ______      __  __   _          __     _______\n");					// ______      __  __   _          __     _______
		printf("        | ___ \\     | | | | | |         | |   (_) ___ \\\n");			// | ___ \     | | | | | |         | |   (_) ___ \ .
		printf("        | |_/ / __ _| |_| |_| | ___  ___| |__  _| |_/ /\n");				// | |_/ / __ _| |_| |_| | ___  ___| |__  _| |_/ /
		printf("        | ___ \\/ _` | __| __| |/ _ \\/ __| '_ \\| |  __/\n");			// | ___ \/ _` | __| __| |/ _ \/ __| '_ \| |  __/
		printf("        | |_/ / (_| | \\_| \\_| |  __/\\__ \\ | | | | |\n");				// | |_/ / (_| | \_| \_| |  __/\__ \ | | | | |
		printf("        \\____/ \\__,_|\\__|\\__|_|\\___\\/___/_| |_\\_\\_|\n\n\n");// \____/ \__,_|\__|\__|_|\___\/___/_| |_\_\_|
		printf("       __  __         _       _          __   __   _    _\n");				//  __  __         _       _          __   __   _    _
		printf("      |  \\/  |__ _ __| |___  | |____  _  \\ \\ / /__(_)__| |\n");		// |  \/  |__ _ __| |___  | |____  _  \ \ / /__(_)__| |
		printf("      | |\\/| / _` | _` / -_) | '_ \\ \\| |  \\ V / _ \\ | _` |\n");	// | |\/| / _` | _` / -_) | '_ \ \| |  \ V / _ \ | _` |
		printf("      |_|  |_\\__,_|__,_\\___\\ |_.__/\\_, |   \\_/\\___/_|__,_|\n");	// |_|  |_\__,_|__,_\___\ |_.__/\_, |   \_/\___/_|__,_|
		printf("                                   |__/\n\n\n");											//                              |__/
		printf("__      ___ _   _      _   _          _        _             __\n");					// __      ___ _   _      _   _          _        _             __
		printf("\\ \\    / (_) |_| |_   | |_| |_  ___  | |_  ___| |_ __   ___ / _|\n");				// \ \    / (_) |_| |_   | |_| |_  ___  | |_  ___| |_ __   ___ / _|
		printf(" \\ \\/\\/ /| |  _| ' \\  |  _| ' \\/ -_) | ' \\/ -_) | '_ \\ / _ \\  _|\n");	//  \ \/\/ /| |  _| ' \  |  _| ' \/ -_) | ' \/ -_) | '_ \ / _ \  _|
		printf("  \\_/\\_/ |_|\\__|_||_|  \\__|_||_\\___| |_||_\\___|_| .__/ \\___/_|\n");		//   \_/\_/ |_|\__|_||_|  \__|_||_\___| |_||_\___|_| .__/ \___/_|
		printf("                                                |_|\n\n\n");									//                                                 |_|
		printf("       ____  _____   ____   __      ___ _ _             _\n");						// ____  _____   ____   __      ___ _ _             _
		printf("       | __| | __ \\ / ___|  \\ \\    / (_) | |__ _ _ ____| |\n");				// | __| | __ \ / ___|  \ \    / (_) | |__ _ _ ____| |
		printf("       | _/  | |/ / \\ \\___   \\ \\/\\/ /| | | / _` | '_/ _` |\n");			// | _/  | |/ / \ \___   \ \/\/ /| | | / _` | '_/ _` |
		printf("       \\_| O |___/O  \\___/O   \\_/\\_/ |_|_|_\\__,_|_| \\__,_|\n\n\n");	// \_| O |___/O  \___/O   \_/\_/ |_|_|_\__,_|_| \__,_|
		printf("Oui je sais il est pas à jour je m'en occuperais plus tard\n\n\n")	//WIP
		return menu();
	}
	else if(x==3){
		return 0;
	}
}

int main(){
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
	printf("Oui je sais il est pas à jour je m'en occuperais plus tard\n\n\n")	//WIP
	return menu();
}
