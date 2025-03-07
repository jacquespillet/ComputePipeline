#pragma once
#include <memory>
#include <string>

namespace Pipeline 
{
class Asset;

enum class Status {
    SUCCESS,
    FIRST_ACTION_NOT_LOAD,
    FILE_LOAD_FAILED,
    INVALID_INPUT
};

/**
 * @brief Struct holding the result of an action, passed around the pipeline
 */
struct ActionResult 
{
    // Wether the action was successful
    Status status;
    // Metadata for the action result
    std::string metadata;
    // The asset that was processed
    std::shared_ptr<Asset> asset;
};

/**
 * @brief Abstract class for an action in the pipeline, implemented for each action
 * 
 */
class Action
{
public:
    Action() = default;

    /**
     * @brief Function that executes an action
     * 
     * @param asset Input ActionResult, containing the asset to process
     * @return std::shared_ptr<const ActionResult> Output ActionResult, containing the processed asset
     */
    virtual std::shared_ptr<ActionResult> Execute(std::shared_ptr<const ActionResult> asset) = 0;
};

/**
 * @brief Action that loads a file from disk, http, or other sources, and stores its binary content into a RawAsset
 * 
 */
class LoadFileContent : public Action
{
public:
    /**
     * @brief Construct a new Load File Content object
     * 
     * @param path Path of the file to load
     */
    LoadFileContent(const std::string &path);

    /**
     * @brief Load the asset from disk
     * 
     * @param asset 
     * @return std::shared_ptr<const ActionResult> 
     */
    virtual std::shared_ptr<ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
private: 

    // Path of the file to load
    std::string m_path;
};

/**
 * @brief Action that decompresses compressed data into a RawAsset
 * 
 */
class Decompress : public Action
{
public:
    /**
     * @brief Construct a new Decompress object
     * 
     */
    Decompress() = default;

    /**
     * @brief Decompress the asset
     * 
     * @param asset 
     * @return std::shared_ptr<const ActionResult> 
     */
    virtual std::shared_ptr<ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
};

/**
 * @brief Action that decodes an input image into a ImageAsset
 * 
 */
class DecodeImage : public Action 
{
public:
    /**
     * @brief Construct a new Decode Image object
     * 
     */
    DecodeImage() = default;

    /**
     * @brief Decode the RawAsset into a ImageAsset
     * 
     * @param asset 
     * @return std::shared_ptr<const ActionResult> 
     */
    virtual std::shared_ptr<ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
};

/**
 * @brief Action that decodes a RawAsset into a JsonAsset
 * 
 */
class ObjectToJson : public Action 
{
public:
    /**
     * @brief Construct a new Object To Json object
     * 
     */
    ObjectToJson() = default;

    /**
     * @brief Parses the raw asset into a JsonAsset
     * 
     * @param asset 
     * @return std::shared_ptr<const ActionResult> 
     */
    virtual std::shared_ptr<ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
};


}