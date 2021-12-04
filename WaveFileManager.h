//class to hold the wave file
#ifndef WAVE_FILE_MANAGER
#define WAVE_FILE_MANAGER

#include <vector>
#include <string>
#include "wav_header.h"

class WaveFileManager {
public:
    std::vector<float> soundData;
    wav_header header;

    WaveFileManager() = default;
    std::string readFile(std::string);
    wav_header getHeader();
};

#endif