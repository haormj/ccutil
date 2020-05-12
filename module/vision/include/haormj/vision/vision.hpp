#ifndef HAORMJ_VISION_VISION_HPP
#define HAORMJ_VISION_VISION_HPP

#include <string>
#include <vector>

#include <torch/script.h>

using std::string;
using std::vector;

namespace haormj {
namespace vision {

class DogsVsCats {
 public:
  const string DOG = "DOG";
  const string CAT = "CAT";

  void load(string pretrainedPath);
  string predict(vector<unsigned char>);
  string predictByUrl(string url);

 private:
  torch::jit::script::Module m;
};

}  // namespace vision
}  // namespace haormj

#endif
