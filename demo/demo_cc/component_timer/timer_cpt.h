#include "cyber/component/component.h"
#include "cyber/component/timer_component.h"

using apollo::cyber::Component;
using apollo::cyber::TimerComponent;

// 自定义类继承 TimerComponent 类，并重写其 Init() 与 Proc() 函数
class MyTimer : public TimerComponent {
 public:
  bool Init() override;
  bool Proc() override;

 private:
  int seq;
};

CYBER_REGISTER_COMPONENT(MyTimer)