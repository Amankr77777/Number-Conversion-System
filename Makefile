CXX ?= g++
CXXFLAGS ?= -std=c++14 -O2 -Wall -Iinclude

all: NumberSystemConverter NumberConverter

NumberSystemConverter: NumberSystemConverter.cpp
	$(CXX) -std=c++11 -O2 -Wall NumberSystemConverter.cpp -o NumberSystemConverter

NumberConverter: src/main.cpp src/Menu.cpp src/Utils.cpp src/BaseConverter.cpp src/FractionalConverter.cpp src/BigIntConverter.cpp src/SignedRepresentation.cpp src/IEEE754Converter.cpp src/SpecialCodes.cpp src/BaseArithmetic.cpp src/StepExplainer.cpp src/TestSuite.cpp
	$(CXX) $(CXXFLAGS) $^ -o NumberConverter

clean:
	rm -f NumberSystemConverter NumberConverter *.exe
