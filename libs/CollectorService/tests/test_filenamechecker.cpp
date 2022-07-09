
#include "CollectorService/FilenameChecker.h"

#include <vector>
#include <string>

#include <gtest/gtest.h>

using namespace CollectorService::FilenameChecker;


class FileNameChecker : public ::testing::Test
{
protected:
    std::vector<std::string> validFileNames;

    void SetUp() override
    {
        validFileNames.emplace_back("core.ServiceName.3057.57dd721409bc4ab4b38a3c33a36a608a.3717.1647975805000000.lz4");
        validFileNames.emplace_back("core.3057.lz4");
        validFileNames.emplace_back("core.ABC.3057.lz4");
        validFileNames.emplace_back("core.abc.3057.lz4");
        validFileNames.emplace_back("core.abc121.3057.lz4");
        validFileNames.emplace_back("core.ABC.ABC.11231.lz4");
        // ...
    }
};


TEST_F(FileNameChecker, StartsWith)
{
    for(const auto& file : this->validFileNames)
    {
        ASSERT_TRUE(isAllowed(file));
    }

    // Copy valid filenames and modify it
    std::vector<std::string> invalidFileNames;
    std::transform(this->validFileNames.cbegin(),
                   this->validFileNames.cend(),
                   std::back_inserter(invalidFileNames),
                   [](auto&& valid) { return "prefix." + valid; });

    for(const auto& file : invalidFileNames)
    {
        EXPECT_THROW(isAllowed(file), std::runtime_error);
    }
}


TEST_F(FileNameChecker, EndsWith)
{
    for(const auto& file : this->validFileNames)
    {
        ASSERT_TRUE(isAllowed(file));
    }

    // Copy valid filenames and modify it
    std::vector<std::string> invalidFileNames;
    std::transform(this->validFileNames.cbegin(),
                   this->validFileNames.cend(),
                   std::back_inserter(invalidFileNames),
                   [](auto&& valid) { return valid + ".suffix"; });

    for(const auto& file : invalidFileNames)
    {
        EXPECT_THROW(isAllowed(file), std::runtime_error);
    }
}

TEST_F(FileNameChecker, ContainsHexIDs)
{
    for(const auto& file : this->validFileNames)
    {
        ASSERT_TRUE(isAllowed(file));
    }

    // Make up a list of non-valid filenames with respect to begin and ending
    std::vector<std::string> invalidFileNames;
    invalidFileNames.emplace_back("core.lz4");
    invalidFileNames.emplace_back("core.ServiceName.lz4");
    invalidFileNames.emplace_back("core.ServiceName.xyz.lz4");
    invalidFileNames.emplace_back("core.ServiceName.34aba2X.lz4");
    // ...

    for(const auto& file : invalidFileNames)
    {
        EXPECT_THROW(isAllowed(file), std::runtime_error);
    }
}