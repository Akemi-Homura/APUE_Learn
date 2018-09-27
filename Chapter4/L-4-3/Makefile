CXX = g++
CXXFLAGS = -g3 -Wall -std=c++11

sources = a.cc
target  = a.out

$(target): $(sources)
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm -rf $(target) *.dSYM
