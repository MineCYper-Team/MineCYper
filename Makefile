CC=gcc
EXECUTABLE_NAME=MineCYper
MODULES_FOLDER=modules/

# Optional (use root if empty)
BUILD_FOLDER=

# Compilation
menu.o :
	@$(CC) -c $(MODULES_FOLDER)menu.c -o $(BUILD_FOLDER)menu.o

map.o :
	@$(CC) -c $(MODULES_FOLDER)map.c -o $(BUILD_FOLDER)map.o

utilities.o :
	@$(CC) -c $(MODULES_FOLDER)utilities.c -o $(BUILD_FOLDER)utilities.o

# Everything at once (should be replaced with a wildcard)
all : menu.o map.o utilities.o
	@$(CC) $(BUILD_FOLDER)menu.o $(BUILD_FOLDER)map.o $(BUILD_FOLDER)utilities.o -o $(EXECUTABLE_NAME)

# Cleaner (should be replaced with a wildcard)
clean :
	@rm -f $(BUILD_FOLDER)menu.o $(BUILD_FOLDER)map.o $(BUILD_FOLDER)utilities.o

# Runners
run : all
	@echo "Running $(EXECUTABLE_NAME)"
	@./$(EXECUTABLE_NAME)

# Release
release : all clean
run_release : release run