CXX = gcc
CXXFLAGS = -g3 -Wall

target	= main myuclc

all: $(target)

main: main.c
	$(CXX) $^ $(CXXFLAGS) -o $@

myuclc: myuclc.c
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm -rf *.dSYM $(target)
