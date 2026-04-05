CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = hotel
SRC = main.cpp headers/CustomerRecordModule.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) -I headers

run: $(TARGET)
	@mkdir -p data
	./$(TARGET)

clean:
	rm -f $(TARGET)