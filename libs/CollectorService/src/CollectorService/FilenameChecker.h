/**
 * @brief Helper function to filter for allowed file names
 *
 * @ingroup CollectorService
 *
 */
#ifndef COLLECTORSERVICE_FILENAMECHECKER_H
#define COLLECTORSERVICE_FILENAMECHECKER_H

#include <string_view>
#include <regex>

namespace CollectorService
{
    namespace FilenameChecker
    {
        static bool isAllowed(std::string_view p_filename)
        {
            // Early exit
            if(p_filename.empty())
            {
                return false;
            }

            // Starts with `core`
            if(!p_filename.starts_with("core"))
            {
                return false;
            }

            // Ends with `lz4`
            if(!p_filename.ends_with("lz4"))
            {
                return false;
            }

            // Contains one or more hexadecimal id separated by dots
            // Built and first tests with https://regex101.com/
            const std::regex reg{"(([0-9a-fA-F]{2})+[.]{1}"};

            if(!std::regex_match(p_filename.data(), reg))
            {
                return false;
            }

            return true;
        }
    }  // namespace FilenameChecker
}  // namespace CollectorService


#endif
