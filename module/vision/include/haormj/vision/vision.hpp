#ifndef HAORMJ_VISION_VISION_HPP
#define HAORMJ_VISION_VISION_HPP

#include <string>

#include "torch/script.h"

using std::string;

namespace haormj {
namespace vision {
class Model {
 public:
  typedef unsigned char *PreprocessFunc(unsigned char *);
  Model();
  Model(string pretrainedPath);
  void preprocess(PreprocessFunc fn, ...);
  unsigned char *predict(unsigned char *input);

 private:
  torch::jit::script::Module m;
};

}  // namespace vision
}  // namespace haormj

#endif
