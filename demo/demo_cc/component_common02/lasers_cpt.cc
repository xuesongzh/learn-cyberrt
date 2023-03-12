#include "cyber/demo_cc/component_common02/lasers_cpt.h"

using apollo::cyber::demo_base_proto::Lasers;

bool LaserCpt::Init() {
  AINFO << ".....lasers filter init.......";
  pub = this->node_->CreateWriter<Lasers>("/laser");
  seq = 0;
  return true;
}

bool LaserCpt::Proc(const std::shared_ptr<Lasers>& front_laser,
                    const std::shared_ptr<Lasers>& back_laser) {
  // 数据融合,消息频率以第一个参数为准
  uint64_t seq_front = front_laser->seq();
  uint64_t seq_back = back_laser->seq();
  uint64_t num_front = front_laser->count();
  uint64_t num_back = back_laser->count();
  uint64_t sum = num_back + num_front;
  AINFO << "total sum = " << sum << ", front seq = " << seq_front
        << ", back seq = " << seq_back;

  seq++;
  // 数据写出
  auto laser = std::make_shared<Lasers>();
  laser->set_seq(seq);
  laser->set_count(sum);
  pub->Write(laser);

  return true;
}