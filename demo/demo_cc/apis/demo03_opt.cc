
#include "cyber/cyber.h"

using apollo::cyber::Duration;
using apollo::cyber::Time;

int main(int argc, char *argv[]) {
  Time t1(100.0);
  Time t2(200.0);
  Time t3(500.0);

  AINFO << " t1 == t2? " << (t1 == t2);
  AINFO << " t1 >= t2? " << (t1 >= t2);
  AINFO << " t1 <= t2? " << (t1 >= t2);

  Duration du1(30.0);
  Duration du2(50.0);
  Duration du3(100.0);

  return 0;
}