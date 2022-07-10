#include "CollectorService/Help.h"
#include "CollectorService/FilenameChecker.h"
#include "CollectorService/Monitor.h"
#include "CollectorService/DiskUsageCollector.h"
#include "CollectorService/DemoCollector.h"

#include "DataCollector/CollectorInstance.h"

#include "Utilities/Utilities.h"

#include <thread>
#include <chrono>
#include <atomic>

#include <iostream>

using namespace CollectorService;

std::atomic<bool> KEEP_SERVICE_RUNNING{true};
void consoleHandler(int signal)
{
    std::cout << "\nSignal received (" << signal << "). Stopping..." << std::endl;
    KEEP_SERVICE_RUNNING = false;

    std::fclose(stdin);  // Bad! Only for demo-code!
}


void printHelp()
{
    std::cout << Help::generateHelpString() << std::endl;
}

void processCommandLineOptions(int argc, char **argv)
{
    // TODO: Parse
    for(int i = 0; i < argc; ++i)
    {
        //std::cout << std::string{argv[i]} << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::cout << "DataCollector Service: WIP" << std::endl;

    // [TODO] Utilities - process and filter argv
    processCommandLineOptions(argc, argv);
    const auto fileToSearchFor = std::filesystem::path("core.1234.lz4");  // Configurable via Commandline args
    const auto logToFolder = std::filesystem::path("./log");              // Configurable via Commandline args
    const auto folderToMonitor = std::string(".");                        // Configurable via Commandline args

    std::string ec;
    if(!FilenameChecker::isAllowed(fileToSearchFor.string(), ec))
    {
        std::cout << "FileName does not match searching criteria: " << fileToSearchFor << std::endl;
        printHelp();
        return -1;
    }

    // Create DataCollector Instance
    auto dataCollector{std::make_unique<DataCollector::CollectorInstance>(logToFolder)};

    // Register collectors. Triggered when monitored file is created
    dataCollector->registerCollector(std::make_shared<DiskUsageCollector>());
    dataCollector->registerCollector(std::make_shared<DemoCollector>());

    // Start monitoring
    Monitor fileMonitor{folderToMonitor, std::move(dataCollector)};

    // Utilities - setup console signal handler (interrupt loop and safe cleanup)
    Utilities::setConsoleSignalHandler(consoleHandler);

    // Operational State -> Loop until SIGINT

    std::cout << "Entering operational state." << std::endl;
    std::cout << "Press Return to simulate a trigger." << std::endl;
    std::cout << "Press Ctrl + C to quit." << std::endl;
    while(KEEP_SERVICE_RUNNING)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds{10});

        if(std::cin.get() == '\n')
        {
            std::cout << "Simulating File Creation for File " << fileToSearchFor.string() << " ..." << std::endl;
            fileMonitor.simulateFileCreation(fileToSearchFor);
        }
    }

    std::cout << "Exit." << std::endl;
    return 0;
}