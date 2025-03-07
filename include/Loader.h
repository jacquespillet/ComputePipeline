#pragma once
#include <string>
#include <vector>
#include <memory>

namespace Pipeline 
{
class Asset;

/**
 * @brief Loader class containing static asset loading functions
 * 
 */
class Loader {
public:
    Loader() = default;
    virtual ~Loader() = default;

    /**
     * @brief Main interface for loading assets, returning a binary buffer
     * 
     * @param assetPath path of the asset to load (http://, file://, bundle://)
     * @param data output buffer
     * @return true if success
     * @return false if failure
     */
    static bool LoadFileContent(const std::string& assetPath, std::vector<uint8_t> &data);
private:
    /**
     * @brief Reads a local file, paths starting with file://
     * 
     * @param assetPath path of the asset to load
     * @param data output buffer
     * @return true if success
     * @return false if failure
     */
    static bool ReadLocalFile(const std::string &assetPath, std::vector<uint8_t> &data);

    
    /**
     * @brief Reads a file with Http protocol, paths starting with http://
     * 
     * @param assetPath path of the asset to load
     * @param data output buffer
     * @return true if success
     * @return false if failure
     */
    static bool ReadHttpFile(const std::string& assetPath, std::vector<uint8_t> &data);

    
    /**
     * @brief Reads a file from a bundle, paths starting with http://
     * 
     * @param assetPath path of the asset to load
     * @param data output buffer
     * @return true if success
     * @return false if failure
     */
    static bool ReadBundleFile(const std::string& assetPath, std::vector<uint8_t> &data);
};
}