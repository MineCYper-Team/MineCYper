//Program
#define RELEASE_VERSION "1.0"

//Compiler directives
#define SEPARATION "------------------------------------------"
#define SPACE "\n         "
#define TUTORIAL_WAIT_TIME 2

//game.c
void beginGame(int width, int height, int number_of_mines);

//menus.c
void showDifficultySelectionMenu();
void showTutorial();
int showMainMenu();

//design.c
void color(int Color);
void coloredText(char * Text, int Color);
void makeTitle(char * Title, int Color);

//utilities.c
int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]);