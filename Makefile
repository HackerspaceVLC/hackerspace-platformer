
PLATFORM := x64

SRC = $(shell find . -name '*.cpp' -exec basename {} \;)
OBJ = $(SRC:.cpp=.o)

# Target specific flags
ifeq ($(MAKECMDGOALS), debug)
CFLAGS += -O0
else
CFLAGS += -O3
endif

# Platform specific flags
ifeq ($(PLATFORM), x64)
CFLAGS += -m64
LDFLAGS += -L"extern/lib/linux64"
else ifeq ($(PLATFORM), rpi)
CFLAGS +=
LDFLAGS += -L"extern/lib/armhf32"
endif

# Global flags
CFLAGS += -g -I"extern/include"
LDFLAGS += -lraylib -lglfw -lGL -lopenal -lm -lpthread -ldl -lBox2D -lX11
CC := g++
LD := g++

.PHONY: all

all: hackerspace-platformer

hackerspace-platformer: $(OBJ)
	$(LD) -o bin/hackerspace-platformer_$(PLATFORM) bin/$(OBJ) $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) -c $(SRC) $(CFLAGS) -o bin/$(OBJ)

clean:
	$(shell find . -name '*.o' -delete)
	$(RM bin/hackerspace-platformer_$(PLATFORM))