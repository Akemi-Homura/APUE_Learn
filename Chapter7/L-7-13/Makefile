CXX = gcc
CXXFLAGS = -g3 -Wall

target = a1.out a2.out

all: $(target)

a1.out: a.c
	$(CXX) $^ $(CXXFLAGS) -o $@

a2.out: a.c
	$(CXX) $^ $(CXXFLAGS) -O -o $@

clean:
	rm -rf *.dSYM $(target)
