/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_CORE_GRAPPLER_OPTIMIZERS_DATA_FUNCTION_RENAME_H_
#define TENSORFLOW_CORE_GRAPPLER_OPTIMIZERS_DATA_FUNCTION_RENAME_H_

#include "tensorflow/core/grappler/optimizers/custom_graph_optimizer.h"

namespace tensorflow {
namespace grappler {

class FunctionRename : public CustomGraphOptimizer {
 public:
  FunctionRename() = default;
  ~FunctionRename() override = default;

  string name() const override { return "_test_only_function_rename"; };

  Status Init(
      const tensorflow::RewriterConfig_CustomGraphOptimizer* config) override {
    return Status::OK();
  }

  Status Optimize(Cluster* cluster, const GrapplerItem& item,
                  GraphDef* output) override;

  void Feedback(Cluster* cluster, const GrapplerItem& item,
                const GraphDef& optimize_output, double result) override;
};

}  // end namespace grappler
}  // end namespace tensorflow

#endif  // TENSORFLOW_CORE_GRAPPLER_OPTIMIZERS_DATA_FUNCTION_RENAME_H_
