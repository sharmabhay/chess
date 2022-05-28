CXX = g++
CXXFLAGS = -std=c++14 -lX11 -Wall -Wextra -Wpedantic -O0 -MMD -Werror=vla -g # use -MMD to generate dependencies
SOURCES = $(wildcard Game/*.cc)   # list of all .cc files in the Game directory
OBJECTS = ${SOURCES:.cc=.o}   # .o files depend upon .cc files with same names
DEPENDS = ${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file
EXEC = chess

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
