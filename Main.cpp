#include <ComputePipeline.h>

using namespace Pipeline;

int main() 
{
    {
        ComputePipeline decompressPipeline;
        decompressPipeline.AddAction(std::make_shared<LoadFileContent>("http://example.com/CopmressedData.zip"))
                          .AddAction(std::make_shared<Decompress>())
                          .Execute();
    }

    {
        ComputePipeline readImgPipeline;
        readImgPipeline.AddAction(std::make_shared<LoadFileContent>("file://home/user/image.jpg"))
                       .AddAction(std::make_shared<DecodeImage>())
                       .Execute();
    }
    
    {
        ComputePipeline readJsonPipelin;
        readJsonPipelin.AddAction(std::make_shared<LoadFileContent>("bundle://home/user/object.json"))
                       .AddAction(std::make_shared<ObjectToJson>())
                       .Execute();
    }
}