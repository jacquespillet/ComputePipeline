#include <Action.h>
#include <iostream>
#include <Loader.h>
#include <Asset.h>
namespace Pipeline 
{

LoadFileContent::LoadFileContent(const std::string &path) : m_path(path) {}

std::shared_ptr<ActionResult> LoadFileContent::Execute(std::shared_ptr<const ActionResult> asset)
{
    std::cout << "Loading file content from " << m_path << std::endl;
    std::shared_ptr<ActionResult> result = std::make_shared<ActionResult>();
    result->asset = std::make_shared<RawAsset>(); //Create a raw asset which will hold the file content
    auto rawAsset = std::dynamic_pointer_cast<RawAsset>(result->asset);
    if (!rawAsset) {
        std::cout << "LoadFileContent: Failed to cast to RawAsset" << std::endl;
        result->status = Status::INVALID_INPUT;
        result->metadata = "Invalid input";
        result->asset = nullptr;
        return result;
    }
    bool success = Loader::LoadFileContent(m_path, rawAsset->Data()); //Load the file content into the asset data
    result->metadata = "Loaded file content"; //Set the metadata
    return result;
}

std::shared_ptr<ActionResult> Decompress::Execute(std::shared_ptr<const ActionResult> input) 
{
    std::cout << "Decompressing data " << std::endl;
    std::shared_ptr<ActionResult> result = std::make_shared<ActionResult>();
    
    //Ensure that the input is a RawAsset (We decompress from a binary buffer)
    std::shared_ptr<RawAsset> rawData = std::dynamic_pointer_cast<RawAsset>(input->asset);
    if(!rawData)
    {
        //If input is not raw data, return an error
        std::cout << "Decompress: Invalid input" << std::endl;
        result->status = Status::INVALID_INPUT;
        result->metadata = "Invalid input";
        result->asset = nullptr;
        return result;
    }

    //Create a new RawAsset to hold the decompressed data
    result->asset = std::make_shared<RawAsset>();
    //Do the decompression with rawData->m_data and write into result->asset
    result->status = Status::SUCCESS;
    result->metadata = "Loaded archive";
    return result;
}


std::shared_ptr<ActionResult> DecodeImage::Execute(std::shared_ptr<const ActionResult> input) 
{
    std::cout << "Decoding Image " << std::endl;
    std::shared_ptr<ActionResult> result = std::make_shared<ActionResult>();
    
    //Ensure that the input is a RawAsset (We decode from a binary buffer)
    std::shared_ptr<RawAsset> rawData = std::dynamic_pointer_cast<RawAsset>(input->asset);
    if(!rawData)
    {
        std::cout << "DecodeImage: Invalid input" << std::endl;
        result->status = Status::INVALID_INPUT;
        result->metadata = "Invalid input";
        result->asset = nullptr;
        return result;
    }
    
    
    result->asset = std::make_shared<ImageAsset>();
    //Do something with rawData->m_data and write into result->asset
    
    result->status = Status::SUCCESS;
    result->metadata = "Loaded image";
    return result;
}


std::shared_ptr<ActionResult> ObjectToJson::Execute(std::shared_ptr<const ActionResult> input) 
{
    std::cout << "Parsing Json " << std::endl;
    std::shared_ptr<ActionResult> result = std::make_shared<ActionResult>();
    
    //Ensure that the input is a RawAsset (We parse from a binary buffer)
    std::shared_ptr<RawAsset> rawData = std::dynamic_pointer_cast<RawAsset>(input->asset);
    if(!rawData)
    {
        std::cout << "ObjectToJson: Invalid input" << std::endl;
        result->status = Status::INVALID_INPUT;
        result->metadata = "Invalid input";
        result->asset = nullptr;
        return result;
    }


    result->asset = std::make_shared<JsonAsset>();
    //Do something with rawData->m_data and write into result->asset

    result->status = Status::SUCCESS;
    result->metadata = "Loaded Json";
    return result;
}




}