CXX = g++
CXXFLAGS = -std=c++11 -pthread -Wall

SRCS = main.cpp classCsv.cpp gis.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = my_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
