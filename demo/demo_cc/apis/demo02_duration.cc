// Duration相关API
#include "cyber/cyber.h"

using apollo::cyber::Duration;
using apollo::cyber::Time;

int main(int argc, char *argv[]) {
  Duration du1(100000);      // ns
  Duration du2(5.0);         // s
  Duration du3(3, 1000000);  // 3.001s

  AINFO << " du2(s) = " << du2.ToSecond();
  AINFO << " du2(ns) = " << du2.ToNanosecond();
  AINFO << " is zero = " << du2.IsZero();

  AINFO << "休眠前：" << Time::Now();
  du2.Sleep();
  AINFO << "休眠后：" << Time::Now();

  return 0;
}