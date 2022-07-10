#include "DataPackager/TarPackager.h"

#include <chrono>
#include <cassert>

#include <cstdlib>  // Only for system call

using namespace DataPackager;


std::filesystem::path TarPackager::packWithUniqueFilename(const std::filesystem::path& p_target)
{
    assert(!p_target.empty());

    const auto uniqueFileName{generateUniqueFilename() + ".tar"};

    /**
     * @brief QND solution
     * Use a dedicated tar-lib for that. For now use pure cmd.
     */

    std::string cmd;
    cmd += "tar ";
    cmd += "-cf ";  // Arguments to pack
    cmd += uniqueFileName + " ";
    cmd += p_target.string();

    system(cmd.c_str());  // QND solution.

    return uniqueFileName;
}

std::string TarPackager::generateUniqueFilename()
{
    // Generate unique filename

    // NOTE: Best to use a UUID Implementation here (e.g. boost uuid)
    // UUIDv1 should be sufficient, better: UUIDv5 with m_target as namespace.
    // ...

    /** For now just use a timestamp
     * Resolution of this cast correlates with the "uniqueness"
     * Note that UUID uniqueness is in the order of 100-nanoseconds intervalls
     * so we should be ok to choose nanoseconds
     */
    const auto now{std::chrono::system_clock::now()};
    return std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count());
}