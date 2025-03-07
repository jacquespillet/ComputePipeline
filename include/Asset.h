#pragma once
#include <vector>
#include <map>
#include <string>


namespace Pipeline 
{

/**
 * @brief Abstract class for an asset, implemented for each asset type
 * 
 */
class Asset 
{
public:
    Asset() = default;
    virtual ~Asset() = default;
};

/**
 * @brief Asset that holds raw binary data
 * 
 */
class RawAsset : public Asset 
{
    public: 
    RawAsset() = default;
    virtual ~RawAsset() = default;
    /**
     * @brief Return the internal binary data
     * 
     * @return std::vector<uint8_t>& 
     */
    std::vector<uint8_t> &Data() { return m_data; }
private: 
    // Binary data
    std::vector<uint8_t> m_data;
};

/**
 * @brief Asset that holds image data
 * 
 */
class ImageAsset : public Asset 
{
public: 
    ImageAsset() = default;
    virtual ~ImageAsset() = default;
private:
    std::vector<uint8_t> m_pixels;
};

/**
 * @brief Asset that holds JSON data
 * 
 */
class JsonAsset : public Asset 
{
public:
    JsonAsset() = default;
    virtual ~JsonAsset() = default;
private:
    //Dummy struct, replace with an actual json library object
    std::map<std::string, std::string> m_jsonData;
};


}