/**
 * @brief Main class to trigger registered data collectors.
 *
 * @class DataCollector::CollectorInstance
 * @ingroup DataCollector
 *
 */
#ifndef DATACOLLECTOR_COLLECTORINSTANCE_H
#define DATACOLLECTOR_COLLECTORINSTANCE_H


#include "DataCollector/CollectorBase.h"

#include <filesystem>
#include <unordered_map>
#include <mutex>

namespace DataCollector
{
    class CollectorInstance
    {
    private:
        const std::filesystem::path m_storeFolder;

        mutable std::mutex m_mutex;
        std::unordered_map<std::size_t, std::shared_ptr<CollectorBase>> m_registeredCollectors;

    public:
        /**
         * @brief Initialize with a folder to store collected data.
         * @throws std::runtime_error If the argument is not a directory or does not exist.
         */
        CollectorInstance(const std::filesystem::path&);
        ~CollectorInstance();

        bool registerCollector(std::shared_ptr<CollectorBase>);

        /**
         * @brief Call all collect functions of all registered data collectors
         * 
         * @return std::filesystem::path of the stored folder
         */
        std::filesystem::path triggerDataCollection() const;


        std::filesystem::path getStoreFolder() const;

    private:
        void checkTargetFolderStatus() const;
    };
}  // namespace DataCollector

#endif
