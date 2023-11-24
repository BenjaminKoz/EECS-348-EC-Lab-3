CXX = g++
TARGET = accounts
SRCS = accounts.cpp
all: $(TARGET)
$(TARGET): $(SRCS)
	$(CXX) -o $@ $(SRCS)
clean:
	rm -f $(TARGET)