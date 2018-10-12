#default variables
# = equals to specify a variable
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXX += -g 
#linker flags (math library, etc) LDFLAGS = _________

OBJS = main.o ant.o inputValidation.o displayMenu.o printBoard.o
SRCS = main.cpp ant.cpp inputValidation.cpp displayMenu.cpp printBoard.cpp
HEADERS = ant.hpp inputValidation.hpp displayMenu.hpp printBoard.hpp


lab1: ${OBJS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o ant


${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean :
	-rm ${OBJS} ant