CXX = gcc
CXXFLAGS = -g3  -Wall

target = tsys printutils

all: $(target)

tsys: tsys.c
	$(CXX) $^ $(CXXFLAGS) -o $@

printutils: printutils.c
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm -rf *.dSYM $(target)
