#include "DataCollector/CollectorInstance.h"

#include <cassert>

using namespace DataCollector;

CollectorInstance::CollectorInstance(const std::filesystem::path& p_folder)
    : m_storeFolder(p_folder)
{
    checkTargetFolderStatus();
}
CollectorInstance::~CollectorInstance() = default;


std::filesystem::path CollectorInstance::getStoreFolder() const
{
    return m_storeFolder;
}

std::filesystem::path CollectorInstance::triggerDataCollection() const
{
    std::lock_guard<std::mutex> lock{m_mutex};
    for(auto& [ID, collector] : m_registeredCollectors)
    {
        collector->collect(*this);
    }

    return getStoreFolder();
}

bool CollectorInstance::registerCollector(std::shared_ptr<CollectorBase> p_collector)
{
    assert(p_collector);

    std::lock_guard<std::mutex> lock{m_mutex};
    if(m_registeredCollectors.contains(p_collector->getID()))
    {
        return false;
    }
    m_registeredCollectors[p_collector->getID()] = p_collector;

    return true;
}

void CollectorInstance::checkTargetFolderStatus() const
{
    // WIP:
    // Race condition as this folder needs to be locked during runtime of the CollectorInstance
    // Else we can get trouble if the folder get moved / deleted at runtime and when a collection is triggered

    if(!std::filesystem::exists(m_storeFolder))
    {
        throw std::runtime_error{"Cannot create CollectorInstance. Folder does not exist!"};
    }
    if(!std::filesystem::is_directory(m_storeFolder))
    {
        throw std::runtime_error{"Cannot create CollectorInstance. Path is not a folder!"};
    }
}