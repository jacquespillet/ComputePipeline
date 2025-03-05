#include <iostream>

#include <Action.h>
#include <Loader.h>
#include <Asset.h>
namespace Pipeline 
{

LoadFileContent::LoadFileContent(const std::string &path) : m_path(path) {}

std::shared_ptr<const ActionResult> LoadFileContent::Execute(std::shared_ptr<const ActionResult> asset)
{
    std::cout << "Loading file content from " << m_path << std::endl;
    std::shared_ptr<ActionResult> result = std::make_shared<ActionResult>();
    result->asset = std::make_shared<RawAsset>();
    result->success = Loader::LoadFileContent(m_path, std::dynamic_pointer_cast<RawAsset>(result->asset)->Data());
    result->metadata = "Loaded file content";
    return result;
}

std::shared_ptr<const ActionResult> Decompress::Execute(std::shared_ptr<const ActionResult> input) 
{
    std::cout << "Decompressing data " << std::endl;
    std::shared_ptr<ActionResult> result = std::make_shared<ActionResult>();
    
    std::shared_ptr<RawAsset> rawData = std::dynamic_pointer_cast<RawAsset>(input->asset);
    if(!rawData)
    {
        std::cout << "Decompress: Invalid input" << std::endl;
        result->success = false;
        return result;
    }


    result->asset = std::make_shared<DecompressedDataAsset>();
    //Do something with rawData->m_data

    result->success = true;
    result->metadata = "Loaded archive";
    return result;
}

}