CC = g++

INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

TARGET = run.out

SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all:$(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)run.out

compile:
	$(BIN_FOLDER)$(TARGET)