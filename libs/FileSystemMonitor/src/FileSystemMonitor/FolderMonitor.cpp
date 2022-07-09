#include "FileSystemMonitor/FolderMonitor.h"


using namespace FileSystemMonitor;


FolderMonitor::FolderMonitor(std::filesystem::path p_folder)
    : m_monitoredFolder(p_folder)
{
    if(!std::filesystem::exists(m_monitoredFolder))
    {
        throw std::runtime_error(p_folder.generic_string() + std::string(" does not exist."));
    }
}
FolderMonitor::~FolderMonitor() = default;