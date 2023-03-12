/*
    需求:订阅发布的消息，并输出
    实现:
        1.头文件；
        2.初始化；
        3.创建节点；
        4.创建订阅方；
        5.回调函数处理数据；
        6.等待关闭。

 */
#include "cyber/demo_base_proto/student.pb.h"

#include "cyber/cyber.h"

using apollo::cyber::demo_base_proto::Student;

void cb(const std::shared_ptr<Student>& stu) {
  AINFO << "name: " << stu->name();
  AINFO << "age: " << stu->age();
  AINFO << "height: " << stu->height();
  for (int i = 0; i < stu->books_size(); i++) {
    AINFO << "books: " << stu->books(i);
  }

  AINFO << "-----------------------------------------";
}

int main(int argc, char* argv[]) {
  // 2.初始化；
  apollo::cyber::Init(argv[0]);
  AINFO << "订阅方创建.....";
  // 3.创建节点；
  auto listener_node = apollo::cyber::CreateNode("cuihua");
  // 4.创建订阅方；
  auto listener = listener_node->CreateReader<Student>("chatter", cb);
  // 5.回调函数处理数据；
  // 6.等待关闭。
  apollo::cyber::WaitForShutdown();

  return 0;
}