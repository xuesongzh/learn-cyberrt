/*
    需求:客户端发送数据并处理响应
    实现:
        1.包含头文件；
        2.初始化 cyber；
        3.创建客户端节点；
        4.创建发布方；
        5.发送数据；
        6.等待关闭。
*/
#include "cyber/demo_base_proto/addints.pb.h"

#include "cyber/cyber.h"

using apollo::cyber::demo_base_proto::AddInts_Request;
using apollo::cyber::demo_base_proto::AddInts_Response;

int main(int argc, char *argv[]) {
  apollo::cyber::Init(argv[0]);
  // 处理输入的参数
  if (argc != 3) {
    AINFO << "执行程序时请输入两个数字作为参数";
    return 1;
  }

  AINFO << "客户端....";
  // 3.创建客户端节点；
  auto client_node = apollo::cyber::CreateNode("client_node");
  // 4.创建发布方；
  auto client =
      client_node->CreateClient<AddInts_Request, AddInts_Response>("addints");
  // 5.发送数据；
  AINFO << "等待服务启动";
  auto request = std::make_shared<AddInts_Request>();
  request->set_num1(atoll(argv[1]));
  request->set_num2(atoll(argv[2]));
  auto flag = client->WaitForService(std::chrono::duration<long int>(10));
  // client->ServiceIsReady
  if (flag) {
    AINFO << "服务已经启动";
    AINFO << "发送num1 = " << request->num1() << ",num2 = " << request->num2();
    auto response = client->SendRequest(request);
    // 处理响应
    AINFO << "响应结果:sum = " << response->sum();
  } else {
    AINFO << "服务未启动";
  }
  // 6.等待关闭。
  apollo::cyber::WaitForShutdown();
  return 0;
}