////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     SubModelBuilders.h (nodes)
//  Authors:  Ofer Dekel
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// predictors
#include "ConstantPredictor.h"
#include "SingleElementThresholdPredictor.h"

// model
#include "ModelGraph.h"
#include "OutputPort.h"
#include "ModelTransformer.h"

namespace nodes
{
    /// <summary> A struct that represents the outputs of a constant predictor sub-model. </summary>
    struct ConstantPredictorSubModelOutputs
    {
        const model::OutputPort<double>& output;
    };

    /// <summary> Builds a part of the model that represents a constant predictor. </summary>
    ///
    /// <param name="model"> [in,out] The model being modified. </param>
    /// <param name="outputPortElements"> The output port elements from which the constant predictor takes its inputs. </param>
    /// <param name="predictor"> The constant predictor. </param>
    ///
    /// <returns> The ConstantPredictorSubModelOutputs. </returns>
    ConstantPredictorSubModelOutputs BuildSubModel(const predictors::ConstantPredictor& predictor, model::Model& model, const model::OutputPortElements<double>& outputPortElements);

    /// <summary> A struct that represents the outputs of a constant predictor sub-model. </summary>
    struct SingleElementThresholdRuleSubModelOutputs
    {
        const model::OutputPort<bool>& output;
    };

    /// <summary> Builds a part of the model that represents a single-element treshold rule. </summary>
    ///
    /// <param name="rule"> The single-element threshold rule. </param>
    /// <param name="model"> [in,out] The model being modified. </param>
    /// <param name="outputPortElements"> The output port elements from which the rule takes its inputs. </param>
    ///
    /// <returns> The SingleElementThresholdRuleSubModelOutputs. </returns>
    SingleElementThresholdRuleSubModelOutputs BuildSubModel(const predictors::SingleElementThresholdPredictor& rule, model::Model& model, const model::OutputPortElements<double>& outputPortElements);
}