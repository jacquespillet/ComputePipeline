#include <iostream>
#include <ComputePipeline.h>
#include <Action.h>

namespace Pipeline 
{

ComputePipeline &ComputePipeline::AddAction(std::shared_ptr<Action> action)
{
    //Push the new action into our list
    m_actions.push_back(action);
    return *this;
}

std::shared_ptr<ActionResult> ComputePipeline::Execute()
{
    //Execute the pipeline
    //Iterate through all actions, and execute them in sequence
    std::shared_ptr<ActionResult> actionResult = std::make_shared<ActionResult>();

    if(m_actions.size() > 0 && !std::dynamic_pointer_cast<LoadFileContent>(m_actions[0]))
    {
        actionResult->status = Status::FIRST_ACTION_NOT_LOAD;
        std::cout << "Cannot Execute Pipeline : First action must be loading a file" << std::endl;
        return actionResult;
    }
    for(auto &action : m_actions)
    {
        actionResult = action->Execute(actionResult);
    
        if(actionResult->status != Status::SUCCESS)
        {
            //If an action fails, print the metadata and return the ActionResult
            //(Could also use other error mechanisms, such as catching exception thrown from Action::Execute, or throw exceptions from this function, etc.)
            std::cout << "Action failed: " << actionResult->metadata << std::endl;
            return actionResult; //Return nullptr to indicate failure
        }
    }
    return actionResult;
}

}