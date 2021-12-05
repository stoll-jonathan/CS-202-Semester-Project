#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "WaveFileManager.h"
#include "wav_header.h"
#include "Processors.h"

int main() {
    WaveFileManager waveFile = WaveFileManager();
    std::string userInput, filename;

    START_MENU:
    std::cout << "WAV Processor" << std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << "Welcome, enter \"file\" to continue or \"quit\" to quit" << std::endl;
    std::cin >> userInput;

    if (userInput == "file") {
        std::cout << "Enter an input filename: ";
        std::cin >> filename;
        std::cout << std::endl;

        //try to open the file
        std::string response = waveFile.readFile(filename);
        if (response != "SUCCESS") {
            std::cout << response << std::endl;
            goto START_MENU;
        }


        //display the metadata
        std::cout << "File Metadata" << std::endl;
        std::cout << "-------------" << std::endl;
        std::cout << "Filename:        " << filename << std::endl;
        std::cout << "Sample Rate:     " << waveFile.getHeader().sample_rate << std::endl;
        std::cout << "Bits Per Sample: " << waveFile.getHeader().bit_depth << std::endl;
        std::cout << "Stereo/Mono:     " << ((waveFile.getHeader().num_channels == 1) ? "Mono" : "Stereo") << std::endl;
        std::cout << std::endl;


        //PROCESSOR MENU
        PROCESSOR_MENU:
        std::cout << "Which processor would you like to run?" << std::endl;
        std::cout << "norm - normalize the audio levels" << std::endl;
        std::cout << "echo - add an echo effect" << std::endl;
        std::cout << "gain - adjust the gain" << std::endl;
        std::cout << "quit - quit the program" << std::endl;
        std::cin >> userInput;


        //run the processors
        if (userInput == "quit") {
            goto QUIT;
        }
        else {
            std::string outputFileName;
            std::cout << "Enter an output filename:" << std::endl;
            std::cin >> outputFileName;

            //ensure the file ends with ".wav"
            if (outputFileName.substr(outputFileName.size() - 4) != ".wav")
                outputFileName.append(".wav");
            
            //these processors will save the file when they are done
            if (userInput == "norm") {
                Processors::normalize(waveFile, outputFileName);
            }
            else if (userInput == "echo") {
                Processors::addEcho(waveFile, outputFileName);
            }
            else if (userInput == "gain") {
                GAIN_MENU:
                float scalingFactor;
                std::cout << "Enter an value to scale by:" << std::endl;
                std::cin >> scalingFactor;
                std::cout << std::endl;

                if (std::cin.fail()) {
                    std::cout << "Error: please enter a number" << std::endl;
                    goto GAIN_MENU;
                }

                Processors::adjustGain(waveFile, outputFileName, scalingFactor);
            }
            else {
                std::cout << "Error: please enter a valid input" << std::endl;
                goto PROCESSOR_MENU;
            }
        }
        
        //go back to start
        goto START_MENU;
    }
    else if (userInput == "quit") {
        goto QUIT;
    }
    else {
        std::cout << "Error: please enter a valid input" << std::endl;
        goto START_MENU;
    }

    QUIT:
    std::cout << "exiting..." << std::endl;
    exit(0);

    return 0;
}
