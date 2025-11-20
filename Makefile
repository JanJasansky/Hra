CC = g++
CFLAGS = -g -fdiagnostics-color=always
SRC = main.cpp game.cpp
TARGET = hra

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o
