#include <iostream>

#include "haormj/vision.hpp"

namespace haormj {
namespace vision {
Model::Model() {}
Model::Model(string pretrainedPath) {
  std::cout << pretrainedPath << std::endl;
}
Model::~Model() {}
}  // namespace vision
}  // namespace haormj
