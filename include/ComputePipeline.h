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

/**
 * @brief This class represents a pipeline of actions that will be executed in sequence.
 * 
 */
class ComputePipeline
{
public:
    ComputePipeline() = default;
    ~ComputePipeline() = default;

    /**
     * @brief Add an action to the pipeline
     * 
     * @param action 
     * @return ComputePipeline& 
     */
    ComputePipeline &AddAction(std::shared_ptr<Action> action);

    /**
     * @brief Execute the pipeline
     * 
     * @return std::shared_ptr<Asset> final asset after all actions have been executed. Returns nullptr if an action fails.
     */
    std::shared_ptr<ActionResult> Execute();

private: 

    // Vector of actions in the pipeline
    std::vector<std::shared_ptr<Action>> m_actions;
};
}