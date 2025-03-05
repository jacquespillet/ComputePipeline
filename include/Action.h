#pragma once
#include <memory>
#include <string>

namespace Pipeline 
{
class Asset;

struct ActionResult 
{
    bool success;
    std::string metadata;
    std::shared_ptr<Asset> asset;
};

class Action
{
public:
    Action() = default;
    
    virtual std::shared_ptr<const ActionResult> Execute(std::shared_ptr<const ActionResult> asset) = 0;
};

class LoadFileContent : public Action
{
public:
    LoadFileContent(const std::string &path);
    virtual std::shared_ptr<const ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
private: 
    std::string m_path;
};

class Decompress : public Action
{
public:
    Decompress() = default;
    virtual std::shared_ptr<const ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
};

class DecodeImage : public Action 
{
public:
    DecodeImage() = default;
    virtual std::shared_ptr<const ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
};

class ObjectToJson : public Action 
{
public:
    ObjectToJson() = default;
    virtual std::shared_ptr<const ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
};

class ArchiveToImage : public Action
{
public:
    ArchiveToImage() = default;
    virtual std::shared_ptr<const ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
};

class ImageToJson : public Action 
{
public:
    ImageToJson() = default;
    virtual std::shared_ptr<const ActionResult> Execute(std::shared_ptr<const ActionResult> asset) override;
};


}