/**
 * @brief Instance to monitor changes inside a specified folder.
 *
 * @class FileSystemMonitor::FolderMonitor
 * @ingroup FileSystemMonitor
 *
 */
#ifndef COLLECTORSERVICE_MONITOR_H
#define COLLECTORSERVICE_MONITOR_H

#include "FileSystemMonitor/FolderMonitor.h"

namespace CollectorService
{
    class Monitor : public FileSystemMonitor::FolderMonitor
    {
    public:
        Monitor(const std::filesystem::path p_path)
            : FileSystemMonitor::FolderMonitor(p_path)
        {
        }

        void onFileCreated(const std::filesystem::path&) override
        {
        }
    };
}  // namespace CollectorService

#endif
