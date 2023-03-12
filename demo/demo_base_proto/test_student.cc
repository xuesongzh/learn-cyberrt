/*
    演示 C++中 protobuf 的基本读写使用
*/
#include "cyber/demo_base_proto/student.pb.h"

int main(int argc, char const *argv[]) {
  // 创建对象
  apollo::cyber::demo_base_proto::Student stu;
  // 数据写
  stu.set_name("zhangsan");
  stu.set_age(18);
  stu.set_height(1.75);
  stu.add_books("yuwen");
  stu.add_books("c++");
  stu.add_books("Python");

  // 数据读
  std::string name = stu.name();
  uint64_t age = stu.age();
  double height = stu.height();
  std::cout << name << " == " << age << " == " << height << std::endl;

  for (int i = 0; i < stu.books_size(); i++) {
    std::cout << stu.books(i) << std::endl;
  }
  std::cout << std::endl;

  return 0;
}