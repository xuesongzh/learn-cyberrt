#!/usr/bin/env python3
"""  
    需求: 服务端设置参数，客户端操作参数
    实现:
        1.包含头文件；
        2.初始化 cyber 框架；
        3.创建节点；
        4.创建参数服务端；
        5.设置参数；
        6.等待关闭。
"""
from cyber.python.cyber_py3 import cyber
from cyber.python.cyber_py3 import parameter

if __name__ == "__main__":
    cyber.init()
    print("param service .....")
    # 3.创建节点；
    param_service_node = cyber.Node("param")
    # 4.创建参数服务端；
    param_service = parameter.ParameterServer(param_service_node)
    # 5.设置参数；
    #
    param1 = parameter.Parameter("type","car_apollo")
    param2 = parameter.Parameter("length",1.5)
    param3 = parameter.Parameter("cameras",2)

    param_service.set_parameter(param1)
    param_service.set_parameter(param2)
    param_service.set_parameter(param3)

    #
    p1 = param_service.get_parameter("type")
    p2 = param_service.get_parameter("length")
    p3 = param_service.get_parameter("cameras")
    print("type = %s,length = %.2f,cameras = %d" %(p1.as_string(), p2.as_double(), p3.as_int64()))

    #  
    ps = param_service.get_paramslist()
    for p in ps:
        print(p.debug_string())

    # while not cyber.is_shutdown():
    #     pass
    param_service_node.spin()
    # 6.等待关闭。
    cyber.shutdown()