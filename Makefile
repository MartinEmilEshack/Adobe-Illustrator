BIN			:= bin
INCLUDE		:= include
LIB			:= lib
SRC			:= src

TOOLS			:= tools
GUI			:= gui

RUN_SCRIPT	:= run.sh
MAIN			:= main.cpp
MAIN_RUNNER := Illustrator.o

GUI_OBJ		:= $(patsubst $(SRC)%,$(BIN)%,$(addsuffix .o, $(basename $(wildcard $(SRC)/$(GUI)*/*.cpp))))
TOOLS_OBJ	:= $(patsubst $(SRC)%,$(BIN)%,$(addsuffix .o, $(basename $(wildcard $(SRC)/$(TOOLS)*/*.cpp))))
LIB_A			:= $(patsubst $(INCLUDE)/%/,$(LIB)/lib_%.a, $(sort $(dir $(wildcard $(INCLUDE)/*/*.h))))

CXXFLAGS	:= -std=c++17 -Wall -Wextra -Wno-unused-parameter -g -lm
CXXFLAGS	+= -lGL -lGLU -lglut
CXXFLAGS	+= -I$(INCLUDE)/$(TOOLS) -I$(INCLUDE)/$(GUI)

PAINTINGS_FLAGS	:= $(CXXFLAGS) -L$(LIB) $(patsubst lib/lib%.a,-l%,$(LIB_A))

.PHONY: run build clean
.SECONDARY: $(BIN)/$(TOOLS)/%.o $(BIN)/$(GUI)/%.o $(LIB_A)
.ONESHELL:
.NOTPARALLEL:
.SILENT:

run: $(TOOLS_OBJ) $(GUI_OBJ) $(LIB_A) $(MAIN_RUNNER)
	bash $(RUN_SCRIPT) $(MAIN_RUNNER)

build: $(TOOLS_OBJ) $(GUI_OBJ) $(LIB_A) $(MAIN_RUNNER)

clean:
	$(RM) $(BIN)/$(TOOLS)/*
	$(RM) $(BIN)/$(GUI)/*

$(BIN)/$(TOOLS)/%.o: $(SRC)/$(TOOLS)/%.cpp $(INCLUDE)/$(TOOLS)/%.h
	echo making tools..'$@' 🔨
	$(CXX) -c '$<' -o '$@' $(CXXFLAGS)

$(BIN)/$(GUI)/%.o: $(SRC)/$(GUI)/%.cpp $(INCLUDE)/$(GUI)/%.h
	echo making gui..'$@' 🔨
	$(CXX) -c '$<' -o '$@' $(CXXFLAGS)

$(LIB)/lib_$(TOOLS).a: $(TOOLS_OBJ)
	echo adding materials..🔗
	ar rcs '$@' $(BIN)/$(TOOLS)/*.o

$(LIB)/lib_$(GUI).a: $(GUI_OBJ)
	echo adding materials..🔗
	ar rcs '$@' $(BIN)/$(GUI)/*.o

$(MAIN_RUNNER): $(SRC)/$(MAIN) $(LIB_A)
	echo polishing paintings.. ['$@'] 🔨
	$(CXX) '$<' -o '$@' $(PAINTINGS_FLAGS)
	chmod ugo+rwx '$@'