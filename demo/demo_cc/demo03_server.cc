/*
    需求:客户端发送请求，提交两个整数，服务端接收请求，提取数字，相加后
        将结果响应回客户端；
    实现:
        1.包含头文件；
        2.初始化；
        3.创建节点；
        4.创建服务方；
        5.数据处理；
        6.等待关闭；


*/
#include "cyber/demo_base_proto/addints.pb.h"

#include "cyber/cyber.h"

using apollo::cyber::demo_base_proto::AddInts_Request;
using apollo::cyber::demo_base_proto::AddInts_Response;

void cb(const std::shared_ptr<AddInts_Request>& request,
        const std::shared_ptr<AddInts_Response>& response) {
  // 处理请求，产生响应
  int64_t num1 = request->num1();
  int64_t num2 = request->num2();
  AINFO << "客户端请求num1=" << num1 << ",num2=" << num2;
  // 求和并设置响应
  int16_t sum = num1 + num2;
  response->set_sum(sum);
}

int main(int argc, char* argv[]) {
  apollo::cyber::Init(argv[0]);
  AINFO << "服务端执行....";
  // 3.创建节点；
  auto server_node = apollo::cyber::CreateNode("server_node");
  // 4.创建服务方；
  auto server = server_node->CreateService<AddInts_Request, AddInts_Response>(
      "addints", cb);
  // 5.数据处理；

  // 6.等待关闭；
  apollo::cyber::WaitForShutdown();
  return 0;
}