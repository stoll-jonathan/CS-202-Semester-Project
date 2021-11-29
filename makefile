WavProcessor: main.o
	g++ -o WavProcessor main.o

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o WavProcessor