PACKAGE=magicmirror

CXX=clang++
LD=clang++
RM=rm
MKDIR=mkdir
PKGCONFIG=pkg-config

OBJ=build/main.o build/FontManager.o
HEADERS=src/main.hpp src/FontManager.hpp src/Singleton.hpp
LIBS=sfml-all

FLAGS=-g
CXXFLAGS=$(FLAGS) -std=c++11 -Wall -Wextra -pedantic-errors -c `$(PKGCONFIG) --cflags $(LIBS)`
LDFLAGS=$(FLAGS) `$(PKGCONFIG) --cflags --libs $(LIBS)`

all : $(PACKAGE)

$(PACKAGE) : build $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $@

clean : 
	$(RM) -rf ./build/
	$(RM) -rf ./$(PACKAGE)

build : 
	$(MKDIR) ./build/

build/%.o : src/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@
