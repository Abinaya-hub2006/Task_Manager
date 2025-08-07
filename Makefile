CXX = g++
CXXFLAGS = -Wall -Iinclude -std=c++11
SRC = src/main.cpp src/TaskManager.cpp
OUT = taskmanager

all: $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)
