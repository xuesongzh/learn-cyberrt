/*
    需求: 服务端设置参数，客户端操作参数
    实现:
        1.包含头文件；
        2.初始化 cyber 框架；
        3.创建节点；
        4.创建参数服务端；
        5.设置参数；
        6.等待关闭。


*/
#include "cyber/cyber.h"
#include "cyber/parameter/parameter_server.h"

using apollo::cyber::Parameter;
using apollo::cyber::ParameterServer;

int main(int argc, char *argv[]) {
  apollo::cyber::Init(argv[0]);
  AINFO << "参数服务端";
  // 3.创建节点, 话题名称和节点名称一样
  std::shared_ptr<apollo::cyber::Node> param_service_node =
      apollo::cyber::CreateNode("car_param");
  // 4.创建参数服务端；
  auto param_service = std::make_shared<ParameterServer>(param_service_node);
  // 5.设置参数；
  param_service->SetParameter(Parameter("type", "apollo_car"));
  param_service->SetParameter(Parameter("height", 1.65));
  param_service->SetParameter(Parameter("lasers", 4));

  // 获取指定参数
  Parameter temp;
  param_service->GetParameter("type", &temp);
  AINFO << temp.Name() << ":" << temp.AsString();
  param_service->GetParameter("height", &temp);
  AINFO << temp.Name() << ":" << temp.AsDouble();
  param_service->GetParameter("lasers", &temp);
  AINFO << temp.Name() << ":" << temp.AsInt64();

  // 获取所有参数
  std::vector<Parameter> params;
  param_service->ListParameters(&params);
  for (auto &&param : params) {
    AINFO << param.Name() << " = " << param.TypeName() << "----"
          << param.DebugString();
  }

  // 6.等待关闭。
  apollo::cyber::WaitForShutdown();
  return 0;
}