#include "Utilities/ConsoleHandler.h"

#include <csignal>

// Wrap away csignal / impl

namespace Utilities
{
    void setConsoleSignalHandler(SignalHandlerType p_signalHandler)
    {
        std::signal(SIGINT, p_signalHandler);
    }
}  // namespace Utilities