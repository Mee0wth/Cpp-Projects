
#default variables
# = equals to specify a variable
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXX += -g 
#linker flags (math library, etc) LDFLAGS = _________

OBJS = main.o castle.o cave.o die.o dungeons.o field.o helper.o item.o link.o space.o tower.o
SRCS = main.cpp castle.cpp cave.cpp die.cpp dungeons.cpp field.cpp helper.cpp item.cpp link.cpp space.cpp tower.cpp
HEADERS = castle.hpp cave.hpp die.hpp dungeons.hpp field.hpp helper.hpp item.hpp link.hpp space.hpp tower.hpp


final: ${OBJS} ${HEADERS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o final


${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


zip:
	zip -D Final_Carey_Linda.zip *.cpp *.hpp makefile *.pdf *.txt

clean :
	-rm ${OBJS} final


