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
        static void isAllowed(std::string_view p_filename)
        {
            // Early exit
            if(p_filename.empty())
            {
                throw std::runtime_error{"Filename empty!"};
            }

            // Starts with `core`
            if(!p_filename.starts_with("core"))
            {
                throw std::runtime_error{"Filename does not start with 'core'!"};
            }

            // Ends with `lz4`
            if(!p_filename.ends_with("lz4"))
            {
                throw std::runtime_error{"Filename does not end with 'lz4'!"};
            }

            // Contains one or more hexadecimal id separated by dots
            // Built and first tests with https://regex101.com/
            const std::regex reg{"([0-9a-fA-F]{2})+[.]{1}"};

            if(!std::regex_search(p_filename.data(), reg))
            {
                throw std::runtime_error{"Filename does not match expected pattern!"};
            }
        }

        static bool isAllowed(std::string_view p_filename, std::string& error_code)
        {
            // Clear EC
            error_code = std::string();

            try
            {
                // Call the exception version
                isAllowed(p_filename);
                return true;
            }
            catch(std::exception& e)
            {
                error_code = std::string(e.what());
                return false;
            }
            return true;  // Satisfy some "non-return" -warnings
        }


    }  // namespace FilenameChecker
}  // namespace CollectorService


#endif
