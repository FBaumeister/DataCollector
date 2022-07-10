/**
 * @brief Some demo collector class. Just printing a text when triggered.
 *
 * @class CollectorService::DemoCollector
 * @ingroup CollectorService
 *
 */
#ifndef COLLECTORSERVICE_DEMOCOLLECTOR_H
#define COLLECTORSERVICE_DEMOCOLLECTOR_H

#include "DataCollector/CollectorBase.h"

#include <iostream>

namespace CollectorService
{
    class DemoCollector : public DataCollector::CollectorBase
    {
    public:
        void collect(const DataCollector::CollectorInstance&) override
        {
            std::cout << "- DemoCollector:collect" << std::endl;
        }
    };
}  // namespace CollectorService

#endif
