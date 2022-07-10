/**
 * @brief Implementation to monitor a folder and trigger datacollection and packaging.
 *
 * @class CollectorService::Monitor
 * @ingroup CollectorService
 *
 */
#ifndef COLLECTORSERVICE_MONITOR_H
#define COLLECTORSERVICE_MONITOR_H

#include "FileSystemMonitor/FolderMonitor.h"
#include "DataCollector/DataCollector_fwd.h"
#include "DataPackager/DataPackager_fwd.h"

namespace CollectorService
{
    class Monitor : public FileSystemMonitor::FolderMonitor
    {
    private:
        std::unique_ptr<DataCollector::CollectorInstance> m_collector;
        std::unique_ptr<DataPackager::TarPackager> m_packager;

    public:
        Monitor(const std::filesystem::path p_path, std::unique_ptr<DataCollector::CollectorInstance>);
        ~Monitor();

        void onFileCreated(const std::filesystem::path&) override;
    };
}  // namespace CollectorService

#endif
