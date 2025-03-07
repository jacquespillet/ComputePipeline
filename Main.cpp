#include <ComputePipeline.h>
#include <assert.h>

using namespace Pipeline;

int main() 
{
    { //Read compressed data from a URL, decompress it into raw data, and decode raw data into image
        ComputePipeline decompressPipeline;
        std::shared_ptr<ActionResult> result = decompressPipeline.AddAction(std::make_shared<LoadFileContent>("http://example.com/CopmressedData.zip"))
                                                                 .AddAction(std::make_shared<Decompress>())
                                                                 .AddAction(std::make_shared<DecodeImage>())
                                                                 .Execute();
        assert(result->status == Status::SUCCESS);
        std::shared_ptr<ImageAsset> imageAsset = std::dynamic_pointer_cast<ImageAsset>(result->asset);
        assert(imageAsset);
    }
    
    { //Read an image and decode it
        ComputePipeline readImgPipeline;
        std::shared_ptr<ActionResult> result = readImgPipeline.AddAction(std::make_shared<LoadFileContent>("file://home/user/image.jpg"))
                                                              .AddAction(std::make_shared<DecodeImage>())
                                                              .Execute();
        assert(result->status == Status::SUCCESS);
        std::shared_ptr<ImageAsset> imageAsset = std::dynamic_pointer_cast<ImageAsset>(result->asset);
        assert(imageAsset);               
    }
    
    { //Read a json object and parse it
        ComputePipeline readJsonPipelin;
        std::shared_ptr<ActionResult> result = readJsonPipelin.AddAction(std::make_shared<LoadFileContent>("bundle://home/user/object.json"))
                                                              .AddAction(std::make_shared<ObjectToJson>())
                                                              .Execute();
        assert(result->status == Status::SUCCESS);
        std::shared_ptr<JsonAsset> jsonAsset = std::dynamic_pointer_cast<JsonAsset>(result->asset);
        assert(jsonAsset);               
    }
    
    { //Error : Decoding an image from a json object
        ComputePipeline readJsonPipelin;
        std::shared_ptr<ActionResult> result = readJsonPipelin.AddAction(std::make_shared<LoadFileContent>("bundle://home/user/object.json"))
                                                              .AddAction(std::make_shared<ObjectToJson>())
                                                              .AddAction(std::make_shared<DecodeImage>())
                                                              .Execute();
        assert(result->status == Status::INVALID_INPUT);
        assert(result->asset == nullptr);
    }
    
    { //Error : First action isn't loading content
        ComputePipeline readJsonPipelin;
        std::shared_ptr<ActionResult> result = readJsonPipelin.AddAction(std::make_shared<ObjectToJson>())
                                                            .AddAction(std::make_shared<ObjectToJson>())
                                                            .AddAction(std::make_shared<DecodeImage>())
                                                            .Execute();
        assert(result->status == Status::FIRST_ACTION_NOT_LOAD);
        assert(result->asset == nullptr);
    }

    
}