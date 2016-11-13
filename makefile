# the name of the executable to be created
BIN_NAME = nessie

CXX = g++
CXXFLAGS = -g -Wall -Wextra
LIBS =

# Folders
SRC_PATH = ./src
BUILD_PATH = ./build
BIN_PATH = ./bin

# Code lists
SRC_EXT = cpp
SOURCES := $(shell find $(SRC_PATH) -type f -name *.$(SRC_EXT))
OBJECTS := $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)
INCLUDES = -I include -I vendor -I /usr/include

# SDL flags
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs)
#SDL_LDFLAGS := $(shell sdl2-config --libs sdl2 SDL2_image)

# Function used to check variables. Use on the command line:
# make print-VARNAME
# Useful for debugging and adding features
print-%: ; @echo $*=$($*)

# link the executable
$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(SDL_LDFLAGS)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT) | dirs
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ $(SDL_CFLAGS)

.PHONY: dirs
dirs:
	mkdir -p $(dir $(OBJECTS))
	mkdir -p $(BIN_PATH)

.PHONEY: clean
clean:
	rm -r build/
