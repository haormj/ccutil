#include <stdio.h>

#include "haormj/http.hpp"

int main() {
  char* url =
      "http://picture.ik123.com/uploads/allimg/170322/3-1F322135106.jpg";
  unsigned char* d;
  unsigned char** data = &d;
  long length = 0;
  length = haormj::http::get(url, data);
  printf("%ld\n", length);

  int i = 0;
  for (i = 0; i < length; i++) {
    if (i >= 160) {
      break;
    }
    if (i % 16 == 0) {
      printf("\n");
    }
    printf("%02x", (*data)[i]);
  }
  printf("\n");
}
