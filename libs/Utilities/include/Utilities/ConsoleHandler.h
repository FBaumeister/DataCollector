/**
 * @brief Simple helper to init the console signal handler
 *
 * @ingroup Utilities
 *
 */
#ifndef UTILITIES_CONSOLEHANDLER_H
#define UTILITIES_CONSOLEHANDLER_H

#include <type_traits>

namespace Utilities
{
    using SignalHandlerType = std::add_pointer_t<void(int)>;

    void setConsoleSignalHandler(SignalHandlerType);

}  // namespace Utilities

#endif
