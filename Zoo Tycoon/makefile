
#default variables
# = equals to specify a variable
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXX += -g 
#linker flags (math library, etc) LDFLAGS = _________

OBJS = main.o menu.o zoo.o animal.o tiger.o penguin.o turtle.o
SRCS = main.cpp menu.cpp zoo.cpp animal.cpp tiger.cpp penguin.cpp turtle.cpp
HEADERS = menu.hpp zoo.hpp animal.hpp tiger.hpp penguin.hpp turtle.hpp


lab1: ${OBJS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o project02


${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean :
	-rm ${OBJS} project02
