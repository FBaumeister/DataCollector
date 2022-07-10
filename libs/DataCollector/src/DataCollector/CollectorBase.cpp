#include "DataCollector/CollectorBase.h"

#include <atomic>

using namespace DataCollector;

CollectorBase::~CollectorBase() = default;

std::size_t CollectorBase::getID() const noexcept
{
    return m_ID;
}

std::size_t CollectorBase::newID() noexcept
{
    static std::atomic<std::size_t> ID{1};
    return ID++;
}