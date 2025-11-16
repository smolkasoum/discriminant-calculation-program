CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = quadratic_solver
SOURCES = diskr.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean
