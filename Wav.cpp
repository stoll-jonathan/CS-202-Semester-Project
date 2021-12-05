#include "Wav.h"

Wav::Wav(std::string filename) {
    filename = filename;

    //8 bit numbers range from 0 to 255 (so a value of 128 represents silence)
    //16 bit numbers range from -32678 to +32678 (so a value of 0 represents silence)
    if (header.bit_depth == 8)
        MAX_SAMPLE_VALUE = 255;
    else if (header.bit_depth == 16)
        MAX_SAMPLE_VALUE = 32678;
}