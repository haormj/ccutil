#include <stdio.h>
#include <iostream>

#include "haormj/http.hpp"

int main() {
  string url =
      "http://picture.ik123.com/uploads/allimg/170322/3-1F322135106.jpg";
  std::cout << url << std::endl;

  std::vector<unsigned char> body = haormj::http::get(url);

  std::cout << body.size() << std::endl;

  int i = 0;
  for (i = 0; i < body.size(); i++) {
    if (i >= 160) {
      break;
    }
    if (i % 16 == 0) {
      printf("\n");
    }
    printf("%02x", body[i]);
  }
  printf("\n");
}
