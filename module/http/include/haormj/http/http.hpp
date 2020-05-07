#ifndef HAORMJ_HTTP_HTTP_HPP
#define HAORMJ_HTTP_HTTP_HPP

#include <string>
#include <vector>

using std::string;

namespace haormj {
namespace http {
std::vector<unsigned char> get(string url);
}
}  // namespace haormj

#endif
