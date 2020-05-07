#include <iostream>

#include "haormj/vision.hpp"

namespace haormj {
namespace vision {
Model::Model() {}
Model::Model(string pretrainedPath) {
  // try {
  //   m = torch::jit::load(pretrainedPath);
  // } catch (const c10::Error &e) {
  //   std::cerr << "error loading the model\n";
  // }
  // std::cout << "model loaded" << std::endl;
  std::cout << pretrainedPath << std::endl;
}
}  // namespace vision
}  // namespace haormj
