//Program
#define RELEASE_VERSION "1.0"

//Compiler directives
#define SEPARATION "------------------------------------------"
#define SPACE "\n         "
#define TUTORIAL_WAIT_TIME 2

//menus.c
void showDifficultySelectionMenu();
void showTutorial();
int showMainMenu();

//design.c
void color(int color);
void makeTitle(char * Title, int Color);

//utilities.c
int provideIntegerChoice(int minimum, int maximum, char RangeFailMessage[], char IntegerFailMessage[]);
