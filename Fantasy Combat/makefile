
#default variables
# = equals to specify a variable
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXX += -g 
#linker flags (math library, etc) LDFLAGS = _________

OBJS = main.o menu.o barbarian.o bluemen.o character.o harrypotter.o medusa.o vampire.o cNode.o deadTeam.o teamOne.o teamTwo.o
SRCS = main.cpp menu.cpp barbarian.cpp bluemen.cpp character.cpp harrypotter.cpp medusa.cpp vampire.cpp cNode.cpp deadTeam.cpp teamOne.cpp teamTwo.cpp
HEADERS = menu.hpp barbarian.hpp bluemen.hpp character.hpp harrypotter.hpp medusa.hpp vampire.hpp cNode.hpp deadTeam.hpp teamOne.hpp teamTwo.hpp


project04: ${OBJS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o project04


${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


zip:
	zip -D project04_carey_linda.zip *.cpp *.hpp makefile *.pdf

clean :
	-rm ${OBJS} project04


