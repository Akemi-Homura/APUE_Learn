CXX = gcc
CXXFLAGS = -g3  -Wall

target = a.out echoall

all: $(target)

a.out: a.c
	$(CXX) $^ $(CXXFLAGS) -o $@

echoall: echoall.c
	$(CXX) $^ $(CXXFLAGS) -o $@
	mv echoall ${HOME}/bin

clean:
	rm -rf *.dSYM $(target)
