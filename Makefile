CXX = g++
CXXFLAGS = -Wall -Wextra
QT_LIBS = -lQt6Widgets -lQt6Core -lQt6Gui -DQT_NO_VERSION_TAGGING
QT_INCLUDES = -I/usr/include/qt6
SRC_DIR = src
BUILD_DIR = build

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/rubik.cpp $(SRC_DIR)/app.cpp
OBJECTS = $(BUILD_DIR)/rubik.o $(BUILD_DIR)/app.o $(BUILD_DIR)/main.o
TARGET = $(BUILD_DIR)/rubik-qt

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(QT_LIBS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(SRC_DIR)/rubik.hpp $(SRC_DIR)/app.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o $(QT_INCLUDES)

$(BUILD_DIR)/rubik.o: $(SRC_DIR)/rubik.cpp $(SRC_DIR)/rubik.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/rubik.cpp -o $(BUILD_DIR)/rubik.o

$(BUILD_DIR)/app.o: $(SRC_DIR)/app.cpp $(SRC_DIR)/app.hpp $(SRC_DIR)/rubik.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/app.cpp -o $(BUILD_DIR)/app.o $(QT_INCLUDES)

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

.PHONY: all clean
