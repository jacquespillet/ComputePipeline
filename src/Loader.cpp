#include <iostream>

#include <Loader.h>
#include <Asset.h>

namespace Pipeline 
{

bool Loader::LoadFileContent(std::string assetPath, std::vector<uint8_t> &data)
{
    //Public interface of the Loader class. Takes any path, and load the file content into the binary buffer, based on the path type
    bool success = false;
    if (assetPath.rfind("file://", 0)==0) success = ReadLocalFile(assetPath, data);
    if (assetPath.rfind("http://", 0)==0 || assetPath.rfind("https://", 0)==0) success = ReadHttpFile(assetPath, data);
    if (assetPath.rfind("bundle://", 0)==0) success = ReadBundleFile(assetPath, data);
    return success;
}

bool Loader::ReadLocalFile(std::string assetPath, std::vector<uint8_t> &data)
{
    std::cout << "Reading Local File " << assetPath << std::endl;
    return true;
}
bool Loader::ReadHttpFile(std::string assetPath, std::vector<uint8_t> &data)
{
    std::cout << "Reading HTTP File " << assetPath << std::endl;
    return true;
}
bool Loader::ReadBundleFile(std::string assetPath, std::vector<uint8_t> &data)
{
    std::cout << "Reading Bundle File " << assetPath << std::endl;
    return true;
}



}