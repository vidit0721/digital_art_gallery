# Makefile for DigitalArtGallery

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Isrc

# Directories
SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
DISPLAY_DIR = $(SRC_DIR)/display
UTILS_DIR = $(SRC_DIR)/utils

# Source files
CORE_SRCS = $(wildcard $(CORE_DIR)/*.cpp)
DISPLAY_SRCS = $(wildcard $(DISPLAY_DIR)/*.cpp)
UTILS_SRCS = $(wildcard $(UTILS_DIR)/*.cpp)
SRCS = $(SRC_DIR)/main.cpp $(CORE_SRCS) $(DISPLAY_SRCS) $(UTILS_SRCS)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = digital_art_gallery

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
