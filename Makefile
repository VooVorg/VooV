# Make Set
ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

all: build

# Paths
BASE_SOURCES := $(wildcard vooc/*.cpp)
COMMON_SOURCES := $(wildcard vooc/common/*.cpp)
LEXER_SOURCES := $(wildcard vooc/lexer/*.cpp)
PARSER_SOURCES := $(wildcard vooc/parser/*.cpp)
AST_SOURCES := $(wildcard vooc/ast/*.cpp)

H_HEADERS := $(wildcard vooc/include/)


ifeq ($(OS),Windows_NT)
	EXECUTABLE := dist/vooc.exe
else
	EXECUTABLE := dist/vooc
endif



# Compilation
CXX = g++
CXXFLAGS = -O1 -pipe -flto -Wall -I./$(H_HEADERS) -std=c++20


$(EXECUTABLE): $(BASE_SOURCES) $(COMMON_SOURCES) $(LEXER_SOURCES) $(PARSER_SOURCES) $(AST_SOURCES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(BASE_SOURCES) $(COMMON_SOURCES) $(LEXER_SOURCES) $(PARSER_SOURCES) $(AST_SOURCES)

build: $(EXECUTABLE)


clean:
	@rm -r dist/*


# Testing

TESTFILES := $(wildcard testing/*.vo)

testfile: %: $(file)
	$(EXECUTABLE) $^

test: $(TESTFILES)
	$(foreach file,$^, $(MAKE) testfile file=$(file);)