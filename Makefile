# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -std=c++17

# Libraries to link
LDFLAGS = -lSDL2 -lSDL2main -lSDL2_image

# Source and object files
SRC = $(wildcard src/*.cpp) chess.cpp
OBJ = $(SRC:.cpp=.o)

# Output binary name
OUT = chess

# Default rule
all: $(OUT)

# How to build the output
$(OUT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

# Optional: Clean up compiled files
clean:
	rm -f $(OUT) $(OBJ)
