# Compiler
CXX = g++
INCLUDE = include

# Compiler flags
CXXFLAGS = -g -std=c++11 -Wall -I$(INCLUDE)

# Source files
SRCS =  main2.cpp person.cpp secretary.cpp student.cpp course.cpp professor.cpp funcs.cpp
# SRCS =  main.cpp person.cpp secretary.cpp student.cpp course.cpp professor.cpp funcs.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = exec  

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Run valgrind on the executable
valgrind: $(TARGET)
	valgrind ./$(TARGET)

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
