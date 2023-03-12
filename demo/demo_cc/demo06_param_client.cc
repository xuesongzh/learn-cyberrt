/*
    需求: 服务端设置参数，客户端操作参数
    实现:
        1.包含头文件；
        2.初始化 cyber 框架；
        3.创建节点；
        4.创建参数客户端；
        5.操作参数；
        6.等待关闭。
*/
#include "cyber/cyber.h"
#include "cyber/parameter/parameter_client.h"

using apollo::cyber::Parameter;
using apollo::cyber::ParameterClient;

int main(int argc, char *argv[]) {
  apollo::cyber::Init(argv[0]);
  AINFO << "参数客户端";
  // 3.创建节点；
  std::shared_ptr<apollo::cyber::Node> param_client_node =
      apollo::cyber::CreateNode("param_client");
  // 4.创建参数客户端；
  auto param_client =
      std::make_shared<ParameterClient>(param_client_node, "car_param");
  // 5.操作参数；
  //
  Parameter temp;
  param_client->GetParameter("type", &temp);
  AINFO << temp.Name() << " = " << temp.AsString();
  param_client->GetParameter("height", &temp);
  AINFO << temp.Name() << " = " << temp.AsDouble();
  param_client->GetParameter("lasers", &temp);
  AINFO << temp.Name() << " = " << temp.AsInt64();
  //
  param_client->SetParameter(Parameter("lasers", 1));
  AINFO << "修改后...";
  param_client->GetParameter("lasers", &temp);
  AINFO << temp.Name() << " = " << temp.AsInt64();

  //
  std::vector<Parameter> ps;
  param_client->ListParameters(&ps);
  for (auto &&p : ps) {
    AINFO << p.Name() << " = " << p.TypeName();
  }

  // 6.等待关闭。
  apollo::cyber::WaitForShutdown();
  return 0;
}