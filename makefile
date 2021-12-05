WavProcessor: main.o WaveFileManager.o Processors.o
	g++ -o WavProcessor main.o WaveFileManager.o Processors.o

main.o: main.cpp
	g++ -c main.cpp

WaveFileManager.o: WaveFileManager.cpp
	g++ -c WaveFileManager.cpp

Processors.o: Processors.cpp
	g++ -c Processors.cpp
	
clean:
	rm *.o WavProcessor