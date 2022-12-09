OUTPUT_DIR = bin
SRC_DIR    = src

SRC_FILES    := $(wildcard $(SRC_DIR)/*.cpp)
OUTPUT_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OUTPUT_DIR)/%.out,$(SRC_FILES))

.PHONY: all clean

$(OUTPUT_DIR)/%.out: $(SRC_DIR)/%.cpp
	g++ -Wall -Werror -std=c++11 -o $@ $<

all: $(OUTPUT_FILES)

clean:
	rm -rf bin/*