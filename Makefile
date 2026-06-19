CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp mode3.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = core.h mode1.h mode3.h

TARGET = program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
