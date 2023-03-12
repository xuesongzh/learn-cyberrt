/*

    将话题消息写入磁盘文件

*/
#include "cyber/demo_base_proto/student.pb.h"

#include "cyber/cyber.h"
#include "cyber/record/record_writer.h"
using apollo::cyber::demo_base_proto::Student;
using apollo::cyber::record::RecordWriter;

int main(int argc, char *argv[]) {
  apollo::cyber::Init(argv[0]);
  AINFO << "record 写操作演示...";
  // 2.创建 recorder 写对象；
  RecordWriter writer;
  // 3.设置写出参数；
  writer.SetSizeOfFileSegmentation(0);
  writer.SetIntervalOfFileSegmentation(0);
  // 4.打开文件流；
  writer.Open("/apollo/cyber/demo_cc/tools/mytest.record");
  AINFO << "file : " << writer.GetFile();

  // 5.写出消息话题以及消息数据；
  writer.WriteChannel("chatter", "apollo.cyber.demo_base_proto.Student",
                      "test ....");
  for (size_t i = 0; i < 10; i++) {
    auto stu = std::make_shared<Student>();
    stu->set_name("huluwa");
    stu->add_books("yingyu");
    stu->add_books("yuwen");
    // stu->SerializeAsString();
    std::string content;
    stu->SerializeToString(&content);
    writer.WriteMessage("chatter", content, i);
    // writer.WriteMessage(channel,stu->SerializeAsString(),i);
  }

  // 6.关闭文件流。
  writer.Close();

  return 0;
}