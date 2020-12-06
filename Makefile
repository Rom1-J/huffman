SOURCES=./src/*.c
HEADERS=./inc
OUTPUT=./

COMPILER=clang
STD=c11

DEBUG=gdbgui

main: clean
	$(COMPILER) -ggdb3 -std=$(STD) -o $(OUTPUT)/main $(SOURCES) -I $(HEADERS)

clean:
	rm -rf $(OUTPUT)/main

run:
	$(OUTPUT)main

debug: main
	$(DEBUG) $(OUTPUT)/main

all: main run