/** @file Processors.h*/
#ifndef PROCESSORS
#define PROCESSORS

#include "WaveFileManager.h"

/**
 *
 *@brief The Processors class is used to modify a wav file.
 *
 * The Processors class normalizes, adds echo, and adjusts gain to wav files
 *
 */
class Processors {
private:
/**
 *
 * @brief Compares the absolute values of two numbers
 *
 * @param a Number compared to b
 * @param b Number compared to a
 * 
 * Compares two values to find the maximum value
 * 
 */
    static bool abs_compare(float a, float b);
/**
 *
 * @brief Saves a given header and soundData vector to a wav file
 *
 * @param header New wav_header object
 * @param soundData Vector to hold audio from wav file
 * @param outFileName The name of the file to be output
 *
 * 
 * 
 */
    static void saveFile(wav_header header, std::vector<float> soundData, std::string outFileName);

public:
 	/**
	 * @brief Normalizes audio of wav file
	 * 
 	 * @param inputFile
 	 *
 	 * @param outFileName The name of the file to be output
 	 *
 	 * Takes in a wav file then normalizes it then outputs it with the requested name
	 */
    static void normalize(WaveFileManager inputFile, const std::string outFileName);
   /**
	 * @brief Adds echo to a wav file
	 * 
 	 * @param inputFile
 	 *
 	 * @param outFileName The name of the file to be output
 	 *
 	 * @param gain Reduces amplitude for the sound
 	 *
 	 * @param delay Gives time delay for the echo
 	 *
 	 * Takes in a wav file then adds echo with the options to adjust gain and delay for the echo, it then outputs a file with the requested name
	 */
    static void addEcho(WaveFileManager inputFile, const std::string outFileName, const float gain, const int delay);
    /**
	 * @brief Adds echo to a wav file
	 * 
 	 * @param inputFile
 	 *
 	 * @param outFileName The name of the file to be output
 	 *
 	 * @param scalingFactor The number by which the amplitude is multiplied
 	 *
 	 * Takes in a wav file then adjusts the gain, it then outputs it with the requested name
	 */
    static void adjustGain(WaveFileManager inputFile, const std::string outFileName, const float scalingFactor);
};

#endif
