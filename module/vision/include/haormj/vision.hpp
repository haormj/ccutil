#include <string>

#include "torch/script.h"

using std::string;

namespace haormj {
namespace vision {
class Model {
 public:
  Model();
  Model(string pretrainedPath);
  ~Model();

 private:
  torch::jit::script::Module m;
};

}  // namespace vision
}  // namespace haormj
