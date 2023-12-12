# Makefile for the 'adv' project

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Include directories
INCLUDES = -I/usr/include/opencv4/

# Libraries
LIBS = -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio

# Source files
SRCS = main.cpp Advertisement.cpp MetricLogger.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = adv

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
