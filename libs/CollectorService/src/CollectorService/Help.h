/**
 * @brief Helper function to get generate executable help string
 *
 * @ingroup CollectorService
 *
 */
#ifndef COLLECTORSERVICE_HELP_H
#define COLLECTORSERVICE_HELP_H

#include <string>

namespace CollectorService
{
    namespace Help
    {
        static std::string generateHelpString()
        {
            std::string help;

            help += " <WIP>\n";
            help += "Currently running with preconfigured values.";


            return help;
        }
    }  // namespace Help
}  // namespace CollectorService


#endif
