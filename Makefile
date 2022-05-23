CC=gcc
EXECUTABLE_NAME=MineCYper

# Optional
BUILD_FOLDER=

# Release
release : all clean
run_release : release run

# Compilation
launcher.o :
	@$(CC) -c launcher.c -o $(BUILD_FOLDER)launcher.o

menus.o :
	@$(CC) -c modules/menus.c -o $(BUILD_FOLDER)menus.o

utilities.o :
	@$(CC) -c modules/utilities.c -o $(BUILD_FOLDER)utilities.o

design.o :
	@$(CC) -c modules/design.c -o $(BUILD_FOLDER)design.o

game.o :
	@$(CC) -c modules/game.c -o $(BUILD_FOLDER)game.o

# Everything at once
all : launcher.o menus.o utilities.o design.o game.o
	@$(CC) $(BUILD_FOLDER)launcher.o $(BUILD_FOLDER)menus.o $(BUILD_FOLDER)utilities.o $(BUILD_FOLDER)design.o $(BUILD_FOLDER)game.o -o $(BUILD_FOLDER)$(EXECUTABLE_NAME)

# Cleaner
clean :
	@rm -f $(BUILD_FOLDER)launcher.o $(BUILD_FOLDER)menus.o $(BUILD_FOLDER)utilities.o $(BUILD_FOLDER)design.o $(BUILD_FOLDER)game.o

# Runners
run : all
	@echo "Running $(EXECUTABLE_NAME)"
	@./$(EXECUTABLE_NAME)
