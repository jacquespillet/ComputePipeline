#pragma once
#include <vector>
#include <memory>

#include "Action.h"
#include "Asset.h"
#include "Loader.h"

namespace Pipeline
{
class Action;
struct ActionResult;

class ComputePipeline
{
public:
    ComputePipeline() = default;
    ~ComputePipeline() = default;

    ComputePipeline &AddAction(std::shared_ptr<Action> action);
    std::shared_ptr<Asset> Execute();

private: 
    std::shared_ptr<const ActionResult> Execute(std::shared_ptr<const ActionResult> asset);

    std::vector<std::shared_ptr<Action>> m_actions;
};
}