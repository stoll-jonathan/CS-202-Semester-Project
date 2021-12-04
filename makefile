WavProcessor: main.o WaveFileManager.o
	g++ -o WavProcessor main.o WaveFileManager.o

main.o: main.cpp
	g++ -c main.cpp

WaveFileManager.o: WaveFileManager.cpp
	g++ -c WaveFileManager.cpp

clean:
	rm *.o WavProcessor