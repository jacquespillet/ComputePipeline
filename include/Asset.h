#pragma once
#include <vector>
#include <map>

namespace Pipeline 
{

class Asset 
{
public:
    Asset() = default;
    virtual ~Asset() = default;
};


class RawAsset : public Asset 
{
    public: 
    RawAsset() = default;
    virtual ~RawAsset() = default;
    std::vector<uint8_t> &Data() { return m_data; }
private: 
    std::vector<uint8_t> m_data;
};

class ImageAsset : public Asset 
{
public: 
    ImageAsset() = default;
    virtual ~ImageAsset() = default;
private: 
    std::vector<uint8_t> m_data;
};


class JsonAsset : public Asset 
{
public: 
    JsonAsset() = default;
    virtual ~JsonAsset() = default;
private: 
    std::map<std::string, std::string> m_data;
};


class DecompressedDataAsset : public Asset 
{
public: 
    DecompressedDataAsset() = default;
    virtual ~DecompressedDataAsset() = default;
private: 
    std::vector<std::string> m_data;
};




}