//class to manage the wave file
#ifndef WAVE_FILE_MANAGER
#define WAVE_FILE_MANAGER

#include <vector>
#include <string>
#include <fstream>
#include "wav_header.h"

class WaveFileManager {
private:
    //8 bit numbers range from 0 to 255 (so a value of 128 represents silence)
    //16 bit numbers range from -32678 to +32678 (so a value of 0 represents silence)
    const int MAX_8BIT = 255, MAX_16BIT = 32678;
    wav_header header;

public:
    WaveFileManager() = default;
    WaveFileManager(wav_header head, std::vector<float> data) : header{head}, soundData{data} {};
    std::vector<float> soundData;
    std::string readFile(std::string);
    void saveFile(std::string);
    wav_header getHeader();
    std::vector<float> getSoundData();

    //read the data into a buffer, then transfer that data to the soundData vector and save each sample as a float
    template<typename bufferType>
    void fillVector(std::ifstream &file, bufferType buffer, const int MAX_SAMPLE_VALUE){
        file.read((char*)buffer, header.num_data_bytes);

        //transfer the data from the buffer to the soundData vector
        for (int i = 0; i < header.num_data_bytes / header.sample_alignment; i++ ) {
            soundData.push_back((float)buffer[i] / MAX_SAMPLE_VALUE); //divide each sample by it's max value to get a range of 0 to 1
        }
    }
};

#endif