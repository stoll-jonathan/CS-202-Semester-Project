#include <fstream>
#include <string.h>
#include "WaveFileManager.h"
#include "wav_header.h"

//try opening the file and send the metadata to the wav_header struct
std::string WaveFileManager::readFile(std::string filename) {

    std::ifstream file(filename, std::ios::binary | std::ios::in);
    //return an error if the file can't be opened
    if (file.fail()) { 
        return ("Error: " + filename + " could not be opened.");
    }
    

    //read the metadata into the header struct
    file.read((char*)&header, sizeof(header));
    
    //reserve memory and read the audio data into the buffer
    short* buffer = new short[header.num_data_bytes];
    file.read((char*)buffer, header.num_data_bytes);
    
    //transfer the data from the buffer to the soundData vector
    for (int i = 0; i < header.num_data_bytes / header.sample_alignment; i++ ) {
        soundData.push_back((float)buffer[i]);
    }
    file.close();


    //return an error if the file isn't a wav file
    if (strcmp(header.wave_header, "WAVE") == 0 || (header.num_channels != 1 && header.num_channels != 2)) {
        return ("Error: " + filename + " is not a WAV file.");
    }
    else return "SUCCESS";
}

wav_header WaveFileManager::getHeader() {
    return header;
}