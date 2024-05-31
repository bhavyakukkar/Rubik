CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC_DIR = src
BUILD_DIR = build

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/rubik.cpp
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/rubik.o
TARGET = $(BUILD_DIR)/rubik-qt

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/rubik.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/rubik.o: $(SRC_DIR)/rubik.cpp $(SRC_DIR)/rubik.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/rubik.cpp -o $(BUILD_DIR)/rubik.o

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
