/*
    需求: 发布学生相关消息
    实现:
        1.头文件；
        2.初始化 cyber 框架；
        3.创建节点；
        4.创建发布者；
        5.组织数据并发布；
        6.等待关闭。

*/
#include "cyber/demo_base_proto/student.pb.h"

#include "cyber/cyber.h"

using apollo::cyber::demo_base_proto::Student;

int main(int argc, char *argv[]) {
  // 2.初始化 cyber 框架
  apollo::cyber::Init(argv[0]);

  // 3.创建节点
  auto talker_node = apollo::cyber::CreateNode("ergou");
  // 4.创建发布者
  auto talker = talker_node->CreateWriter<Student>("chatter");
  // 5.组织数据并发布
  uint64_t seq = 0;  // 计数器
  apollo::cyber::Rate rate(0.5);
  while (apollo::cyber::OK()) {
    seq++;
    AINFO << "发布第" << seq << "条数据！";
    // 组织数据
    auto msg = std::make_shared<Student>();
    msg->set_name("huluwa");
    msg->set_age(seq);
    msg->set_height(1.72);
    msg->add_books("chinese");
    msg->add_books("math");
    msg->add_books("english");

    // 发布
    talker->Write(msg);
    rate.Sleep();
  }

  // 6.等待关闭
  apollo::cyber::WaitForShutdown();

  return 0;
}