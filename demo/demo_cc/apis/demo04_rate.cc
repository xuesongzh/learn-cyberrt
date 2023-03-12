
#include "cyber/cyber.h"

using apollo::cyber::Rate;
using apollo::cyber::Time;

int main(int argc, char *argv[]) {
  Rate r1(0.5);

  AINFO << "休眠前：" << Time::Now();
  r1.Sleep();
  AINFO << "休眠后：" << Time::Now();

  return 0;
}