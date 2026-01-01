CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Isrc
SRCDIR = src
OBJDIR = obj
BINDIR = .

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/calendar

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "Build successful! Executable: $(TARGET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
