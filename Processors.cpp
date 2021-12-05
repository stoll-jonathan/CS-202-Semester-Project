#include "Processors.h"
#include <algorithm>


//TODO: edit header metadata after you process it


//normalizes the audio and calls saveFile
void Processors::normalize(WaveFileManager inputFile, std::string outFileName) {
    saveFile(inputFile.getHeader(), inputFile.getSoundData(), outFileName);
}

//adds an echo effect and calls saveFile
void Processors::addEcho(WaveFileManager inputFile, std::string outFileName) {
    saveFile(inputFile.getHeader(), inputFile.getSoundData(), outFileName);
}

//adjusts the gain and calls saveFile
void Processors::adjustGain(WaveFileManager inputFile, std::string outFileName) {
    saveFile(inputFile.getHeader(), inputFile.getSoundData(), outFileName);
}

//compares the absolute value of two floats
bool Processors::abs_compare(float a, float b) {
    return std::abs(a) < std::abs(b);
}

//save a given header and soundData vector to a wav file
void Processors::saveFile(wav_header header, std::vector<float> soundData, std::string outFileName) {
    const int MAX_8BIT = 255, MAX_16BIT = 32678;
    std::ofstream outfile(outFileName, std::ios::out | std::ios::binary);

    //find the maximum value in the soundData vector
    auto maxLocation = std::max_element(soundData.begin(), soundData.end(), abs_compare);
    float maxValue = *maxLocation;

    if (header.bit_depth == 8) {
        unsigned char* buffer = new unsigned char[header.num_data_bytes];

        //normalize the sound data and put it in a buffer
        for (int i = 0; i < soundData.size(); i++) {
            soundData[i] = soundData[i] / maxValue;
            buffer[i] = (char)(soundData[i] * MAX_8BIT);
        }

        //write the header and buffer to the output file
        outfile.write((char*)&header, sizeof(header));
        outfile.write((char*)buffer, header.num_data_bytes);
    }
    else if (header.bit_depth == 16) {
        short* buffer = new short[header.num_data_bytes];

        //normalize the sound data and put it in a buffer
        for (int i = 0; i < soundData.size(); i++) {
            soundData[i] = soundData[i] / maxValue;
            buffer[i] = (short)(soundData[i] * MAX_16BIT);
        }

        //write the header and buffer to the output file
        outfile.write((char*)&header, sizeof(header));
        outfile.write((char*)buffer, header.num_data_bytes);
    }

    outfile.close();
}