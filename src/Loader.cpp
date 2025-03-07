#include <Loader.h>
#include <iostream>
#include <Asset.h>

namespace Pipeline 
{

bool Loader::LoadFileContent(const std::string &assetPath, std::vector<uint8_t> &data)
{
    //Public interface of the Loader class. Takes any path, and load the file content into the binary buffer, based on the path type
    bool success = false;
    if (assetPath.rfind("file://", 0)==0) success = ReadLocalFile(assetPath, data);
    if (assetPath.starts_with("http://") || assetPath.starts_with("https://")) success = ReadHttpFile(assetPath, data);
    if (assetPath.starts_with("bundle://")) success = ReadBundleFile(assetPath, data);
    return success;
}

bool Loader::ReadLocalFile(const std::string &assetPath, std::vector<uint8_t> &data)
{
    std::cout << "Reading Local File " << assetPath << std::endl;
    return true;
}
bool Loader::ReadHttpFile(const std::string &assetPath, std::vector<uint8_t> &data)
{
    std::cout << "Reading HTTP File " << assetPath << std::endl;
    return true;
}
bool Loader::ReadBundleFile(const std::string &assetPath, std::vector<uint8_t> &data)
{
    std::cout << "Reading Bundle File " << assetPath << std::endl;
    return true;
}



}