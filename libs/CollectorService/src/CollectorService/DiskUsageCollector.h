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

#include <iostream>
#include <fstream>

namespace CollectorService
{
    class DiskUsageCollector : public DataCollector::CollectorBase
    {
    public:
        struct CollectedDiskUsageData
        {
            std::size_t freeByesOnDrive{42};
            // etc.

            std::string toString() const
            {
                // WIP: Use JSON or some other format here...
                std::string toString;
                toString = "free = " + std::to_string(freeByesOnDrive);


                return toString;
            }
        };


        void collect(const DataCollector::CollectorInstance& p_instance) override
        {
            std::cout << "- DiskUsageCollector:collect" << std::endl;
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
            auto filename = p_targetPath.string() + "/diskusage.txt";

            std::ofstream file(filename);
            // Write data to file
            file << p_data.toString();
        }
    };
}  // namespace CollectorService

#endif
