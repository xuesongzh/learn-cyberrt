#include "cyber/demo_cc/component_timer/timer_cpt.h"

#include "cyber/component/component.h"

bool MyTimer::Init() {
  AINFO << "timer component init ......";
  seq = 0;
  return true;
}

bool MyTimer::Proc() {
  seq++;
  AINFO << "--------------------------" << seq;

  return true;
}