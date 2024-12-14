CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDE = -I./SDL2/include
LIBS = -L./SDL2/lib -lmingw32 -lSDL2main -lSDL2
SRCS = ./src/main.cpp ./src/framework.cpp
OBJS = main.o framework.o coordinate.o circle.o rigidbody.o square.o
TARGET = main.exe

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(INCLUDE) $(LIBS) -o $(TARGET)

main.o: ./src/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

framework.o: ./src/framework.cpp ./include/framework.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

coordinate.o: ./src/vector.cpp ./include/vector.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

circle.o: ./src/circle.cpp ./include/circle.h ./include/shape.h 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

rigidbody.o: ./src/rigidbody.cpp ./include/rigidbody.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

square.o: ./src/square.cpp ./include/square.h ./include/shape.h 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	del /q $(OBJS) $(TARGET)
