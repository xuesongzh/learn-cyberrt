#include <iostream>

#include "cyber/demo_base_bazel/pro2_lib/demo_lib/hello_great.h"
using namespace std;
int main(int argc, char const *argv[]) {
  cout << get_great("demo lib") << endl;
  return 0;
}