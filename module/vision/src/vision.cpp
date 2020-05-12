#include <iostream>
#include <stdexcept>

#include <opencv2/imgproc/types_c.h>
#include <opencv2/opencv.hpp>

#include <haormj/http.hpp>
#include <haormj/vision.hpp>

namespace haormj {
namespace vision {
void DogsVsCats::load(string pretrainedPath) {
  try {
    m = torch::jit::load(pretrainedPath);
  } catch (const c10::Error &e) {
    throw std::runtime_error(e.msg());
  }
}

string DogsVsCats::predict(vector<unsigned char> data) {
  cv::Mat image = cv::imdecode(static_cast<cv::Mat>(data), cv::IMREAD_COLOR);
  if (image.empty()) {
    throw std::runtime_error("image is empty");
  }

  cv::cvtColor(image, image, CV_BGR2RGB);
  cv::Mat img_float;
  image.convertTo(img_float, CV_32F, 1.0 / 255);

  // resize
  cv::resize(img_float, img_float, cv::Size(224, 224));
  auto img_tensor =
      torch::from_blob(img_float.data, {1, 224, 224, 3}).to(torch::kCPU);
  img_tensor = img_tensor.permute({0, 3, 1, 2});
  // normalize
  img_tensor[0][0] = img_tensor[0][0].sub_(0.485).div_(0.229);
  img_tensor[0][1] = img_tensor[0][1].sub_(0.456).div_(0.224);
  img_tensor[0][2] = img_tensor[0][2].sub_(0.406).div_(0.225);
  auto img_var = torch::autograd::make_variable(img_tensor, false);
  std::vector<torch::jit::IValue> inputs;
  inputs.emplace_back(img_var);
  // {'cat': 0, 'dog': 1}
  torch::Tensor out_tensor = m.forward(inputs).toTensor();

  if (out_tensor.argmax().equal(torch::tensor(0, torch::kInt64))) {
    return CAT;
  }
  return DOG;
}

string DogsVsCats::predictByUrl(string url) {
  std::vector<unsigned char> data = haormj::http::get(url);
  return predict(data);
}

}  // namespace vision
}  // namespace haormj
