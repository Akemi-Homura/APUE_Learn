CXX = gcc
CXXFLAGS = -g3 -Wall

sources = a.c signal_util.c
target 	= a.out

$(target): $(sources)
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm -rf *.dSYM $(target)
