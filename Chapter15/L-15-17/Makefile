CXX = gcc
CXXFLAGS = -g3 -Wall

target = main add2

all: $(target)

main: main.c
	$(CXX) $^ $(CXXFLAGS) -o $@

add2: add2.c
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm -rf *.dSYM $(target)
