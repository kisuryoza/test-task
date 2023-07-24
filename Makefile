CXX = g++
CXXFLAGS := -Wall -g -fconcepts-ts -std=c++20 -static

TARGET_EXEC := bin
BUILD_DIR := target
SRC_DIR := src

SRCS := main.cpp Point2D.cpp Polygon.cpp

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -fr $(BUILD_DIR)
	rm -f results.txt
