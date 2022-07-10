/**
 * @brief Instance to monitor changes inside a specified folder.
 *
 * @class FileSystemMonitor::FolderMonitor
 * @ingroup FileSystemMonitor
 *
 */
#ifndef FILESYSTEMONITOR_FOLDERMONITOR_H
#define FILESYSTEMONITOR_FOLDERMONITOR_H

#include <filesystem>

namespace FileSystemMonitor
{
    class FolderMonitor
    {
    private:
        const std::filesystem::path m_monitoredFolder;

    public:
        /**
         * @brief Pass in the folder to monitor
         * @throws std::runtime_error Throws if the folder to monitor does not exist. 
         *
         */
        FolderMonitor(const std::filesystem::path);
        virtual ~FolderMonitor();

        /**
         * @brief Notifies that a new file was created inside the specified folder.
         * 
         */
        virtual void onFileCreated(const std::filesystem::path&)
        {
        }

        // WIP -> extendable with other notifications later
        void simulateFileCreation(const std::filesystem::path& p_file);
    };
}  // namespace FileSystemMonitor

#endif
