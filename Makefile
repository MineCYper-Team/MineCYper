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

grid.o :
	@$(CC) -c modules/grid.c -o $(BUILD_FOLDER)grid.o

utilities.o :
	@$(CC) -c modules/utilities.c -o $(BUILD_FOLDER)utilities.o

# Everything at once (should be replaced with a wildcard)
all : minesweeper.o grid.o utilities.o
	@$(CC) $(BUILD_FOLDER)minesweeper.o $(BUILD_FOLDER)grid.o $(BUILD_FOLDER)utilities.o -o $(EXECUTABLE_NAME)

# Cleaner (should be replaced with a wildcard)
clean :
	@rm -f $(BUILD_FOLDER)minesweeper.o $(BUILD_FOLDER)grid.o $(BUILD_FOLDER)utilities.o

# Runners
run : all
	@echo "Running $(EXECUTABLE_NAME)"
	@./$(EXECUTABLE_NAME)
