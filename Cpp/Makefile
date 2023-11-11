%: %.cpp
	g++ -Wall -Wextra -Wconversion -static -DONLINE_JUDGE -Wl,-z,stack-size=268435456 -O2 -std=c++17 -o $@.o $<

clean:
	rm -rf *.o