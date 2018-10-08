CXX = clang
CXXFLAGS = -g3 -Wall

sources = a.c
target	= a.out

$(target): $(sources)
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm -rf *.dSYM $(target)
