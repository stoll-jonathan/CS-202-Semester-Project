//class to hold the wav file
#ifndef WAV
#define WAV

#include <string>
#include <vector>
#include "wav_header.h"

class Wav {
private:
    std::string filename;
    int MAX_SAMPLE_VALUE;
    

public:
    wav_header header;
    std::vector<float> soundData;
    Wav(std::string);
    wav_header getHeader();
    std::vector<float> getSoundData();
};

#endif