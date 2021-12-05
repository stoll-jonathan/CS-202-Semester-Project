/** @file WaveFileManager.h*/
//class to manage the wave file
#ifndef WAVE_FILE_MANAGER
#define WAVE_FILE_MANAGER

#include <vector>
#include <string>
#include <fstream>
#include "wav_header.h"

/**
 *
 *@brief Manages the wave file
 *
 * Grabs data from a wave file and puts data into the wav_header struct 
 *
 */
class WaveFileManager {
private:
    //8 bit numbers range from 0 to 255 (so a value of 128 represents silence)
    //16 bit numbers range from -32678 to +32678 (so a value of 0 represents silence)
    const int MAX_8BIT = 255, MAX_16BIT = 32678;
    wav_header header;

public:
	   /**
		 *
 		 * @brief Default constructor
 		 * Default constructor for WaveFileManager
		 */
    WaveFileManager() = default;
     /**
		 *
 		 * @brief Construct new WaveFileManager
 		 * 
 		 * @param head New wav_header object
 		 *
 		 * @param data Vector to hold audio from wav file
 	 	 *
		 */
    WaveFileManager(wav_header head, std::vector<float> data) : header{head}, soundData{data} {};
    /**
     * @brief Float vector
     */
    std::vector<float> soundData;
    /**
     * @brief Opens the file and send the metadata to the wav_header struct
     */
    std::string readFile(std::string);
    void saveFile(std::string);
    /**
     * @brief Returns header
     */
    wav_header getHeader();
    /**
     * Returns soundData
     */
    std::vector<float> getSoundData();

    /**
    * @brief Reads data into soundData vector
    * @tparam bufferType
    * @param &file
    * @param buffer
    * @param MAX_SAMPLE_VALUE
    * Reads the data into a buffer, then transfer that data to the soundData vector and save each sample as a float
    */
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
