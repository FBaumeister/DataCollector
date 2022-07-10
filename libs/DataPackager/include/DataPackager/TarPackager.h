/**
 * @brief Provides functionality to pack data into tarballs.
 *
 * @class DataPackager::TarPackager
 * @ingroup DataPackager
 *
 */
#ifndef DATAPACKAGER_TARPACKAGER_H
#define DATAPACKAGER_TARPACKAGER_H

#include <filesystem>
#include <string>

namespace DataPackager
{
    class TarPackager
    {
    public:
        /**
         * @brief Packs the given target to a uniquely named tarball.
         * @throws std::runtime_error Throws on packaging error.
         * @return Contains the path to the packed tarball.
         */
        static std::filesystem::path packWithUniqueFilename(const std::filesystem::path&);


        static std::string generateUniqueFilename();
    };
}  // namespace DataPackager

#endif
