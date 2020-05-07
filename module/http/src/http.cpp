#include <stdexcept>

#include <curl/curl.h>

#include <haormj/http.hpp>

namespace haormj {
namespace http {

size_t getBodyCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;

  std::vector<unsigned char> *buff =
      static_cast<std::vector<unsigned char> *>(userp);
  unsigned char *ptr = static_cast<unsigned char *>(contents);

  for (int i = 0; i < realsize; i++) {
    (*buff).push_back(ptr[i]);
  }

  return realsize;
}

std::vector<unsigned char> get(string url) {
  CURL *curl;
  CURLcode res;
  std::vector<unsigned char> buff;

  curl = curl_easy_init();
  // init curl error throw error
  if (!curl) {
    throw std::runtime_error("curl_easy_init error");
  }
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buff);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getBodyCallback);

  // Perform the request, res will get the return code
  res = curl_easy_perform(curl);
  // Check for errors
  if (res != CURLE_OK) {
    string errMsg = curl_easy_strerror(res);
    throw std::runtime_error(errMsg);
  }
  // always cleanup
  curl_easy_cleanup(curl);

  return buff;
}

}  // namespace http
}  // namespace haormj
