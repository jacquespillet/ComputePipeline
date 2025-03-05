#include <iostream>
#include <ComputePipeline.h>
#include <Action.h>

namespace Pipeline 
{

ComputePipeline &ComputePipeline::AddAction(std::shared_ptr<Action> action)
{
    m_actions.push_back(action);
    return *this;
}

//Main interface
std::shared_ptr<Asset> ComputePipeline::Execute()
{
    std::shared_ptr<const ActionResult> result = Execute(nullptr);
    return result->asset;
}

std::shared_ptr<const ActionResult> ComputePipeline::Execute(std::shared_ptr<const ActionResult> actionResult)
{
    for(auto &action : m_actions)
    {
        actionResult = action->Execute(actionResult);
        if(!actionResult->success)
        {
            std::cout << "Action failed: " << actionResult->metadata << std::endl;
            return actionResult;
        }
    }
    return actionResult;
}

}