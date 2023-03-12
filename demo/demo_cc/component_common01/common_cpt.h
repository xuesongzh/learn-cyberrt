#include "cyber/demo_base_proto/student.pb.h"

/*
1、自定义类继承 Component 类，并重写其 Init() 与 Proc() 函数；
2、注册组件类
*/

#include "cyber/demo_base_proto/student.pb.h"

#include "cyber/component/component.h"

using apollo::cyber::Component;
using apollo::cyber::demo_base_proto::Student;

class CommonCpt : public Component<Student> {
 public:
  // Init() 函数是用于初始化的，只会执行一次
  bool Init() override;
  // Proc()函数在订阅到消息时就会被回调执行
  bool Proc(const std::shared_ptr<Student>& stu) override;
};
CYBER_REGISTER_COMPONENT(CommonCpt)