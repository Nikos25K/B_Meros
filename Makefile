# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -std=c++11 -Wall

# Source files
SRCS = main.cpp person.cpp secretary.cpp student.cpp course.cpp

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
