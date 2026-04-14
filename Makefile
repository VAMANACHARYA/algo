CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SOURCES = prefixSumUtils.cpp prefixSum2D.cpp
HEADERS = prefixSumUtils.h prefixSum2D.h

# Targets
.PHONY: all demo interactive test clean

all: demo interactive test

demo: prefix_sum
	@echo "Running basic demo..."
	./prefix_sum

prefix_sum: prefix_sum.cpp $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o prefix_sum prefix_sum.cpp $(SOURCES)

interactive: interactive.cpp $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o interactive interactive.cpp $(SOURCES)
	@echo "Interactive program compiled successfully!"
	@echo "Run with: ./interactive"

test: test.cpp $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o test test.cpp $(SOURCES)
	@echo "Running tests..."
	./test

clean:
	rm -f prefix_sum interactive test
	rm -f *.o
	@echo "Cleaned up compiled files!"

help:
	@echo "Available targets:"
	@echo "  make all        - Compile everything"
	@echo "  make demo       - Compile and run basic demo"
	@echo "  make interactive - Compile interactive program"
	@echo "  make test       - Compile and run unit tests"
	@echo "  make clean      - Remove compiled files"
	@echo "  make help       - Show this help message"
