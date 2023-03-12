
#include "cyber/cyber.h"

using apollo::cyber::Timer;

void cb() { AINFO << "---------------"; }

int main(int argc, char *argv[]) {
  Timer timer(100, cb, false);

  timer.Start();
  sleep(3);
  timer.Stop();

  return 0;
}