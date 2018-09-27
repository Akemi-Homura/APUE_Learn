CXX = gcc
CXXFLAGS = -g3 -Wall

sources = test.c
target  = test

$(target): $(sources)
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm -rf $(target) *.dSYM
