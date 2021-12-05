#ifndef PROCESSORS
#define PROCESSORS

#include "WaveFileManager.h"

class Processors {
private:
    static bool abs_compare(float, float);
    static void saveFile(wav_header, std::vector<float>, std::string);

public:
    static void normalize(WaveFileManager, std::string);
    static void addEcho(WaveFileManager, std::string);
    static void adjustGain(WaveFileManager, std::string, float);
};

#endif