/**
 * @brief Implementation of a DataCollector to collect information on DiskUsage
 *
 * @class CollectorService::DiskUsageCollector
 * @ingroup CollectorService
 *
 */
#ifndef COLLECTORSERVICE_DISKUSAGECOLLECTOR_H
#define COLLECTORSERVICE_DISKUSAGECOLLECTOR_H

#include "DataCollector/CollectorBase.h"
#include "DataCollector/CollectorInstance.h"

namespace CollectorService
{
    class DiskUsageCollector : public DataCollector::CollectorBase
    {
    public:
        struct CollectedDiskUsageData
        {
            std::size_t freeByesOnDrive;
            // etc.
        };


        void collect(const DataCollector::CollectorInstance& p_instance) override
        {
            // Collect data
            const auto collectedData{collectDiskUsage()};

            // Output to preconfigured folder
            writeDiskUsage(collectedData, p_instance.getStoreFolder());
        }

    private:
        CollectedDiskUsageData collectDiskUsage()
        {
            // collect relevant data
            CollectedDiskUsageData data;
            //data.free = ...
            return data;
        }

        void writeDiskUsage(const CollectedDiskUsageData& p_data, const std::filesystem::path& p_targetPath)
        {
            // Write the output to p_targetPath
        }
    };
}  // namespace CollectorService

#endif
