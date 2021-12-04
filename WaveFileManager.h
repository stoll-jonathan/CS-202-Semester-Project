//class to hold the wave file
#ifndef WAVE_FILE_MANAGER
#define WAVE_FILE_MANAGER

#include <vector>
#include <string>
#include "wav_header.h"

class WaveFileManager {
private:
    wav_header header;

public:
    std::vector<float> soundData;

    WaveFileManager() = default;
    std::string readFile(std::string);
    wav_header getHeader();
};

#endif