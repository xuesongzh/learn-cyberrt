// Time API
#include "cyber/cyber.h"

using apollo::cyber::Time;

int main(int argc, char *argv[]) {
  Time t1;                            // 1970-1-1 08：00：00 时间原点
  Time t2(100);                       // ns
  Time t3(100.0);                     // s
  Time right_now = Time::Now();       // 获取当前时刻
  Time mono_time = Time::MonoTime();  // 获取系统启动到当前时刻的时间

  AINFO << " t1 = " << t1;
  AINFO << " t2 = " << t2;
  AINFO << " t3 = " << t3;
  AINFO << " right_now = " << right_now;
  AINFO << " mono_time = " << mono_time;

  // 休眠10s
  Time rn = Time::Now();
  Time fu = Time(rn.ToSecond() + 10);

  AINFO << "休眠前：" << rn;
  Time::SleepUntil(fu);
  AINFO << "休眠后：" << Time::Now();

  return 0;
}
