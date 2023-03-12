#include "cyber/cyber.h"
/*
    需求: 在控制台输出文本HelloWorld;
*/

int main(int argc, char *argv[]) {
  apollo::cyber::Init(argv[0]);
  AINFO << "hello world!";
  return 0;
}