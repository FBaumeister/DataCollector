
#include "CollectorService/Help.h"

#include "Utilities/Utilities.h"

#include <thread>
#include <chrono>
#include <atomic>

#include <iostream>

using namespace CollectorService;

std::atomic<bool> KEEP_SERVICE_RUNNING{true};  // qnd

void consoleHandler(int signal)
{
    std::cout << "\nSignal received (" << signal << "). Stopping..." << std::endl;
    KEEP_SERVICE_RUNNING = false;
}


void printHelp()
{
    std::cout << Help::generateHelpString() << std::endl;
}

void processCommandLineOptions(int argc, char **argv)
{
    std::cout << "WIP: processCommandLineOptions" << std::endl;
    for(int i = 0; i < argc; ++i)
    {
        std::cout << std::string{argv[i]} << std::endl;
        // WIP
    }
}

int main(int argc, char **argv)
{
    std::cout << "DataCollector Service: WIP" << std::endl;


    // [TODO] Utilities - process and filter argv
    processCommandLineOptions(argc, argv);
    std::string fileToMonitor = "core.1234.lz4";  // WIP
    /*if(!Utilities::filterFileName(fileToMonitor))
    {
        printHelp();
        return -1;
    }*/


    // Utilities - setup console signal handler (interrupt loop and safe cleanup)
    Utilities::setConsoleSignalHandler(consoleHandler);

    // [TODO] Create DataCollector Instance
    // [TODO] Register Collectors

    // [TODO] Create DataPackager Instance
    // [TODO] Setup to package data on new data collection

    // [TODO] Create FileSystemMonitor
    // [TODO] Link: onFileCreated - trigger to DataCollector

    // loop and wait for signal handler to capture SIGINT
    std::cout << "Entering operational state..." << std::endl;
    while(KEEP_SERVICE_RUNNING)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds{10});
    }

    std::cout << "Exit." << std::endl;
    return 0;
}