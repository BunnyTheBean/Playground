main: main.cpp dice.o normalDistribution.o exactDiceDistribution.o
	g++ -o main main.cpp dice.o normalDistribution.o exactDiceDistribution.o

dice.o: dice.cpp
	g++ -c -o dice.o dice.cpp

normalDistribution.o: normalDistribution.cpp
	g++ -c -o normalDistribution.o normalDistribution.cpp

exactDiceDistribution.o: exactDiceDistribution.cpp
	g++ -c -o exactDiceDistribution.o exactDiceDistribution.cpp