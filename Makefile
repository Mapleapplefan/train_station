CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -gdwarf-4 -Wall -Wextra -pedantic -fsanitize=address,null -Wno-error=unused $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./includes/train.hpp ./src/train.cc ./includes/train_car.hpp ./includes/utilities.hpp
	$(CXX) $(CXXFLAGS) ./src/driver.cc ./src/train.cc -o $@

bin/tests: obj/catch_main.o ./tests/tests.cc ./includes/train.hpp ./includes/train_car.hpp ./src/train.cc
	$(CXX) $(CXXFLAGS) obj/catch_main.o ./tests/tests.cc ./src/train.cc -o $@

obj/catch_main.o: ./tests/catch.cc ./tests/catch.hpp
	$(CXX) $(CXX_FLAGS) -c ./tests/catch.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*