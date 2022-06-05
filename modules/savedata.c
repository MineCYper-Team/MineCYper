#include "header.h"

typedef struct {
	char * username;
	int rawTime;
} TimeRecord;

void showBestTimes(char * fileName, int size){
	//"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHH" --JordanViknar, 2022-06-05

	printf("\n");

	FILE * file = fopen(fileName, "r");
	char line[30] = {};

	//We get the number of entries in the file
	int numberOfRecords = 0;
	while (fgets(line, 30, file) != NULL){
		numberOfRecords++;
	}

	//We put everything in a table
	TimeRecord * BestTimes = malloc(sizeof(TimeRecord) * numberOfRecords);
	rewind(file);
	bzero(line, sizeof(line));
	int i = 0;
	while (fgets(line, 30, file) != NULL){
		BestTimes[i].username = malloc(sizeof(char) * strlen(line));
		strcpy(BestTimes[i].username, strtok(line, ";"));
		BestTimes[i].rawTime = atoi(strtok(NULL, ";"));
		i++;
	}

	//Then we sort this table
	for (int i = 0; i < numberOfRecords - 1; i++){
		for (int j = 0; j < numberOfRecords - i - 1; j++){
			if (BestTimes[j].rawTime > BestTimes[j + 1].rawTime){
				TimeRecord temp = BestTimes[j];
				BestTimes[j] = BestTimes[j + 1];
				BestTimes[j + 1] = temp;
			}
		}
	}

	//And display it
	int numberOfBestTimes = min(size, numberOfRecords);
	for(int i = 0; i < numberOfBestTimes; i++){
		char * savedTimeAsClock = timeToClock(BestTimes[i].rawTime);
		printf("%d. %s - %s\n", i+1, BestTimes[i].username, savedTimeAsClock);
		free(savedTimeAsClock);
	}

	fclose(file);
}

void saveAndShowTime(int timeOnBeginning, int endgameResult, char * fileName){
	if(endgameResult == 1){
		int timeResult = time(NULL) - timeOnBeginning;
		char *timeString = timeToClock(time(NULL) - timeOnBeginning);
		printf("Your time : %s\n\n", timeString);

		// Ask for username, and replace the character ; with ,
		char username[20];
		printf("Please enter your username : ");
		scanf("%19s", username);
		for(int i = 0; i < strlen(username); i++){
			if(username[i] == ';'){
				username[i] = ',';
			}
		}

		FILE * file = fopen(fileName, "a");
		fprintf(file, "%s;%d\n", username, timeResult);
		fclose(file);

		printf("\nFastest times :");
		showBestTimes(fileName, 5);
		printf("\n");
	}
}

bool doesFileExist(char * fileName){
	FILE * file = fopen(fileName, "r");
	if(file == NULL){
		return false;
	}
	fclose(file);
	return true;
}