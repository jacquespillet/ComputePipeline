# Compute Pipeline

## Description

This is a simple compute pipeline abstraction. A compute pipeline allows to process data in a streamlined manner.

A pipeline is composed of a set of actions, executed sequencially. An action always takes an "Asset" as input, and outputs an "Asset" itself (Except for loading actions, that don't have inputs)

An asset can be anything that contains data. In this implementation, the most simple asset is a RawAsset, which is just a binary buffer. 

But an asset could also be raster image, a video frame, an audio file, a text document, and so on.

Here's an example of how to use it. 

This example loads a compressed file from a web server, decompresses the content of that file, and then decode the result into a raster image.

```cpp
ComputePipeline decompressPipeline;
std::shared_ptr<ActionResult> result = decompressPipeline.AddAction(std::make_shared<LoadFileContent>("http://example.com/CopmressedData.zip"))
                                                         .AddAction(std::make_shared<Decompress>())
                                                         .AddAction(std::make_shared<DecodeImage>())
                                                         .Execute();
assert(result->status == Status::SUCCESS);
std::shared_ptr<ImageAsset> imageAsset = std::dynamic_pointer_cast<ImageAsset>(result->asset);
assert(imageAsset);
```

The first action of a pipeline must always be a LoadFileContent action, which will read the file content into a binary buffer. 

This buffer is then passed throughout the pipeline to be for example : 

* Decoded as an image

* Decompressed from a compressed data format

* Parsed from json to an object representation

The final asset is then returned by the ComputePipeline::Execute() function.


## Configuration : 
```
* Clone the repo
git clone  https://github.com/jacquespillet/ComputePipeline.git
cd ComputePipeline

* Generate the solution and build
mkdir build
cmake -S . -B build
cmake --build build --config Release
```

## Error Handling

The errors of execution in the pipeline are handled using error codes. 

When an action fails, it will systematically break out of the pipeline execution.

The Pipeline::Execute() function will return the error code thrown by the step of the pipeline that failed.
