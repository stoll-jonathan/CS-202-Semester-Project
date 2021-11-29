#include <iostream>
#include <fstream>
#include <string.h>
#include "wav_header.h"

int main() {
    std::string userInput, filename;

    START_MENU:
    std::cout << "WAV Processor" << std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << "Welcome, enter \"file\" to continue or anything else to quit" << std::endl;
    std::cin >> userInput;

    if (userInput == "file") {
        std::cout << "Enter an input filename: ";
        std::cin >> filename;
        std::cout << std::endl;

        //try opening the file and send the metadata to the wav_header struct
        wav_header header;
        std::ifstream file(filename, std::ios::binary | std::ios::in);
        //go back to start if the file can't be opened
        if (file.fail()) { 
            std::cout << "Error: " << filename << " could not be opened." << std::endl;
            goto START_MENU;
        }
        else {
            file.read((char*) &header, sizeof(header));
            file.close();
        }
        //go back to start if the file isn't a wav file
        if (strcmp(header.wave_header, "WAVE") == 0 || (header.num_channels != 1 && header.num_channels != 2)) {
            std::cout << "Error: " << filename << " is not a WAV file." << std::endl;
            goto START_MENU;
        }
        

        //display the metadata
        std::cout << "File Metadata" << std::endl;
        std::cout << "-------------" << std::endl;
        std::cout << "Filename:        " << filename << std::endl;
        std::cout << "Sample Rate:     " << header.sample_rate << std::endl;
        std::cout << "Bits Per Sample: " << header.bit_depth << std::endl;
        std::cout << "Stereo/Mono:     " << ((header.num_channels == 1) ? "Mono" : "Stereo") << std::endl;
        std::cout << std::endl;


        //PROCESSOR MENU
        std::cout << "Which processor would you like to run?" << std::endl;
        std::cout << "norm - normalize the audio levels" << std::endl;
        std::cout << "echo - add an echo effect" << std::endl;
        std::cout << "gain - adjust the gain" << std::endl;
        std::cout << "quit - quit the program" << std::endl;
        std::cin >> userInput;

        if (userInput == "quit")
            goto QUIT;
        else {
            std::string outFilename;
            std::cout << "Enter an output filename: ";
            std::cin >> outFilename;
            std::cout << std::endl;
        
            //run the processors
            if (userInput == "norm") {

            }
            else if (userInput == "echo") {

            }
            else if (userInput == "gain") {

            }

            //save the file
        }
        //go back to start
        goto START_MENU;
    }
    else {
        goto QUIT;
    }

    QUIT:
    std::cout << "exiting..." << std::endl;
    exit(1);

    return 0;
}
