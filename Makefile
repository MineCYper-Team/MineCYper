CC=gcc
EXECUTABLE_NAME=MineCYper
MODULES_FOLDER=modules/

# Optional
BUILD_FOLDER=

# Compilation
launcher.o :
	@$(CC) -c launcher.c -o $(BUILD_FOLDER)launcher.o

menus.o :
	@$(CC) -c $(MODULES_FOLDER)menus.c -o $(BUILD_FOLDER)menus.o

utilities.o :
	@$(CC) -c $(MODULES_FOLDER)utilities.c -o $(BUILD_FOLDER)utilities.o

design.o :
	@$(CC) -c $(MODULES_FOLDER)design.c -o $(BUILD_FOLDER)design.o

# Everything at once (should be replaced with a wildcard)
all : launcher.o menus.o utilities.o design.o
	@$(CC) $(BUILD_FOLDER)launcher.o $(BUILD_FOLDER)menus.o $(BUILD_FOLDER)utilities.o $(BUILD_FOLDER)design.o -o $(EXECUTABLE_NAME)

# Cleaner (should be replaced with a wildcard)
clean :
	@rm -f $(BUILD_FOLDER)launcher.o $(BUILD_FOLDER)menus.o $(BUILD_FOLDER)utilities.o $(BUILD_FOLDER)design.o

# Runners
run : all
	@echo "Running $(EXECUTABLE_NAME)"
	@./$(EXECUTABLE_NAME)

# Release
release : all clean
run_release : release run
