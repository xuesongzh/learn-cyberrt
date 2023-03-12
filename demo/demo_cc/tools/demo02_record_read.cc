#include "cyber/cyber.h"
#include "cyber/record/record_message.h"
#include "cyber/record/record_reader.h"

using apollo::cyber::record::RecordMessage;
using apollo::cyber::record::RecordReader;

int main(int argc, char *argv[]) {
  apollo::cyber::Init(argv[0]);

  AINFO << "record 读操作演示...";
  RecordReader reader("/apollo/cyber/demo_cc/tools/mytest.record");
  // 读取话题相关数据
  std::string channel = "chatter";
  uint64_t msg_count = reader.GetMessageNumber(channel);
  AINFO << "总共" << msg_count << "条消息";
  std::string msg_type = reader.GetMessageType(channel);
  std::string msg_desc = reader.GetProtoDesc(channel);
  AINFO << "消息类型:" << msg_type;
  AINFO << "消息描述:" << msg_desc;
  // 读取消息内容
  RecordMessage msg;
  for (size_t i = 0; i < msg_count; i++) {
    if (reader.ReadMessage(&msg)) {
      AINFO << "第" << i << "条消息 -> "
            << "channel name: " << msg.channel_name
            << "; content: " << msg.content << "; msg time: " << msg.time;
    } else {
      AINFO << "消息读取失败.....";
    }
  }

  return 0;
}