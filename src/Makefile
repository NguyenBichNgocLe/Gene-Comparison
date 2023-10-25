CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror=return-type -Werror=uninitialized -Wpedantic -g

OBJECTS = main.o bruteForce.o similarityMeasure.o
NAME = main

$(NAME): $(OBJECTS)
		$(CXX) $^ -o $(NAME)
		$(RM) *.o

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
		$(RM) *.o $(NAME)