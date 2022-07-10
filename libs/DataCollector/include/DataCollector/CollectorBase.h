/**
 * @brief Base class of a collector to be derived from and registered with the main instance.
 *
 * @class DataCollector::CollectorBase
 * @ingroup DataCollector
 *
 */
#ifndef DATACOLLECTOR_COLLECTORBASE_H
#define DATACOLLECTOR_COLLECTORBASE_H

#include "DataCollector/DataCollector_fwd.h"

#include <cstddef>

namespace DataCollector
{
    class CollectorBase
    {
    private:
        const std::size_t m_ID{newID()};

    public:
        virtual ~CollectorBase();

        std::size_t getID() const noexcept;

        /**
         * @brief Called by the respective Instance when registered.
         * Use this to write your custom code to write your data.
         * Passed in CollectorInstance can be used to query conextual information.
         */
        virtual void collect(const CollectorInstance&) = 0;

    private:
        static std::size_t newID() noexcept;
    };
}  // namespace DataCollector

#endif
