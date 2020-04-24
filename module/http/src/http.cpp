#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include <curl/curl.h>

#include "haormj/http/http.hpp"

namespace haormj {
namespace http {

struct MemoryBuffer {
  unsigned char *memory;
  size_t size;
};

size_t getBodyCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryBuffer *mem = (struct MemoryBuffer *)userp;

  unsigned char *ptr =
      (unsigned char *)realloc(mem->memory, mem->size + realsize + 1);
  if (ptr == NULL) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }

  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

size_t getContentLengthCallback(const void *ptr, size_t size, size_t nmemb,
                                void *buff) {
  int r;
  long contentLength = 0;
  r = sscanf((char *)ptr, "Content-Length: %ld\n", &contentLength);
  if (r) {
    *((long *)buff) = contentLength;
  }
  return size * nmemb;
}

int get(char *url, unsigned char **data) {
  CURL *curl;
  CURLcode res;
  long contentLength = 0;
  struct MemoryBuffer chunk;
  // will be grown as needed by the realloc above
  chunk.memory = (unsigned char *)malloc(1);
  // no data at this point
  chunk.size = 0;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA, &contentLength);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, getContentLengthCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getBodyCallback);

    // Perform the request, res will get the return code
    res = curl_easy_perform(curl);
    // Check for errors
    if (res != CURLE_OK) {
      std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res)
                << std::endl;
      return -1;
    }
    // always cleanup
    curl_easy_cleanup(curl);
  }
  *data = new unsigned char[contentLength];
  memcpy(*data, chunk.memory, chunk.size);
  free(chunk.memory);

  return contentLength;
}

}  // namespace http
}  // namespace haormj
