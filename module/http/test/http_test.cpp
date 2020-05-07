#include <iostream>
#include <vector>

#include <gtest/gtest.h>

#include <haormj/http.hpp>

namespace haormj {
namespace http {
TEST(getTest, length) {
  std::vector<unsigned char> data = haormj::http::get("https://baidu.com");
  std::cout << data.size() << std::endl;
}
}  // namespace http
}  // namespace haormj
