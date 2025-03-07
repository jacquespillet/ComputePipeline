#pragma once
#include <vector>
#include <memory>

#include "Action.h"
#include "Asset.h"
#include "Loader.h"

namespace Pipeline
{
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
    ComputePipeline &AddAction(const std::shared_ptr<Action>& action);
    /**
     * @brief Execute the pipeline
     * 
     * This method executes each action in the pipeline sequentially. An action is considered to have failed if it returns an error status.
     * If any action fails, the pipeline execution stops immediately
     * 
     * @return std::shared_ptr<ActionResult> final result after all actions have been executed.
     */
    std::shared_ptr<ActionResult> Execute() const;

private: 

    // Vector of actions in the pipeline
    std::vector<std::shared_ptr<Action>> m_actions;
};
}