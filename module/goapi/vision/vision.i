%module vision

%{
#include <haormj/vision.hpp>
%}

%include "std_string.i"
%include "std_vector.i"

namespace std {
  %template(ByteVector) vector<unsigned char>;
}

%include "../../vision/include/haormj/vision/vision.hpp"
