#ifndef PROCESSORS
#define PROCESSORS

#include "WaveFileManager.h"

class Processors {
private:
    static bool abs_compare(float, float);
    static void saveFile(wav_header, std::vector<float>, std::string);

public:
    static void normalize(WaveFileManager, const std::string);
    static void addEcho(WaveFileManager, const std::string, const float, const int);
    static void adjustGain(WaveFileManager, const std::string, const float);
};

#endif