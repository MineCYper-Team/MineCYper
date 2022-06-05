CC=gcc
EXECUTABLE_NAME=MineCYper

# Optional (use root if empty)
BUILD_FOLDER=

# Release
release : all clean
run_release : release run

# Compilation
minesweeper.o :
	@$(CC) -c modules/minesweeper.c -o $(BUILD_FOLDER)minesweeper.o

map.o :
	@$(CC) -c modules/map.c -o $(BUILD_FOLDER)map.o

utilities.o :
	@$(CC) -c modules/utilities.c -o $(BUILD_FOLDER)utilities.o

init.o :
	@$(CC) -c modules/init.c -o $(BUILD_FOLDER)init.o

game.o :
	@$(CC) -c modules/game.c -o $(BUILD_FOLDER)game.o

savedata.o :
	@$(CC) -c modules/savedata.c -o $(BUILD_FOLDER)savedata.o

# Everything at once
all : minesweeper.o map.o utilities.o init.o game.o savedata.o
	@$(CC) $(BUILD_FOLDER)minesweeper.o $(BUILD_FOLDER)map.o $(BUILD_FOLDER)utilities.o $(BUILD_FOLDER)init.o $(BUILD_FOLDER)game.o $(BUILD_FOLDER)savedata.o -o $(EXECUTABLE_NAME)

# Cleaner
clean :
	@rm -f $(BUILD_FOLDER)minesweeper.o $(BUILD_FOLDER)map.o $(BUILD_FOLDER)utilities.o $(BUILD_FOLDER)init.o $(BUILD_FOLDER)game.o $(BUILD_FOLDER)savedata.o

# Runners
run : all
	@echo "Running $(EXECUTABLE_NAME)"
	@./$(EXECUTABLE_NAME)
