#pragma once
#include <string>
#include <vector>
#include <memory>

namespace Pipeline 
{
class Asset;

class Loader {
public:
    Loader() = default;
    virtual ~Loader() = default;
    static bool LoadFileContent(std::string assetPath, std::vector<uint8_t> &data);
private:
    static bool ReadLocalFile(std::string assetPath, std::vector<uint8_t> &data);
    static bool ReadHttpFile(std::string assetPath, std::vector<uint8_t> &data);
    static bool ReadBundleFile(std::string assetPath, std::vector<uint8_t> &data);
};
}