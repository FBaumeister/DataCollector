#include "CollectorService/Monitor.h"
#include "CollectorService/FilenameChecker.h"

#include "DataCollector/CollectorInstance.h"
#include "DataPackager/TarPackager.h"


#include <iostream>
#include <cassert>

using namespace CollectorService;

Monitor::Monitor(const std::filesystem::path p_path, std::unique_ptr<DataCollector::CollectorInstance> p_collector)
    : FileSystemMonitor::FolderMonitor(p_path)
    , m_collector(std::move(p_collector))
    , m_packager(std::make_unique<DataPackager::TarPackager>())
{
    assert(m_collector);
    assert(m_packager);
}
Monitor::~Monitor() = default;  // Keep dependencies inside this translation unit

void Monitor::onFileCreated(const std::filesystem::path& p_created)
{
    // Filter
    std::string ec;
    if(FilenameChecker::isAllowed(p_created.string(), ec))  // Use the non-exception version
    {
        return;
    }

    try
    {
        // Trigger DataCollector
        const auto folderToPack = m_collector->triggerDataCollection();
        auto packedTarball = m_packager->packWithUniqueFilename(folderToPack);
    }
    catch(std::exception& e)
    {
        std::cout << "Failed to collect data " << e.what() << std::endl;
    }
}