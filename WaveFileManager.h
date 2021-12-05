//class to hold the wave file
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
    std::vector<float> soundData;
    void fillVector8Bit(std::ifstream &);
    void fillVector16Bit(std::ifstream &);

public:
    WaveFileManager() = default;
    std::string readFile(std::string);
    wav_header getHeader();
    std::vector<float> getSoundData();
    void saveFile(std::string);
};

#endif