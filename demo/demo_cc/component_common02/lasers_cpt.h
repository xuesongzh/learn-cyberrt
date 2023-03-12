#include "cyber/demo_base_proto/lasers.pb.h"

#include "cyber/component/component.h"

using apollo::cyber::Component;
using apollo::cyber::demo_base_proto::Lasers;

// 自定义类继承 Component 类，并重写其 Init() 与 Proc() 函数
class LaserCpt : public Component<Lasers, Lasers> {
 public:
  bool Init() override;
  bool Proc(const std::shared_ptr<Lasers>& front_laser,
            const std::shared_ptr<Lasers>& back_laser) override;

 private:
  // 发布者
  std::shared_ptr<apollo::cyber::Writer<Lasers>> pub = nullptr;
  uint64_t seq;
};

// 在cyber中注册组件
CYBER_REGISTER_COMPONENT(LaserCpt)