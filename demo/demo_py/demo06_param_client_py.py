#!/usr/bin/env python3
"""  
    需求: 服务端设置参数，客户端操作参数
    实现:
        1.包含头文件；
        2.初始化 cyber 框架；
        3.创建节点；
        4.创建参数客户端；
        5.操作参数；
        6.等待关闭。
"""
from cyber.python.cyber_py3 import cyber
from cyber.python.cyber_py3 import parameter

if __name__ == "__main__":
    cyber.init()
    print("param client .....")
    # 3.创建节点；
    param_client_node = cyber.Node("param_client_node")
    # 4.创建参数客户端；
    client = parameter.ParameterClient(param_client_node,"param")
    # 5.操作参数；
    p1 = client.get_parameter("type")
    p2 = client.get_parameter("length")
    p3 = client.get_parameter("cameras")
    print("type = %s,length = %.2f,cameras = %d" %(p1.as_string(), p2.as_double(), p3.as_int64()))
    client.set_parameter(parameter.Parameter("cameras",100))
    p4 = client.get_parameter("cameras")
    print("type = %s,length = %.2f,cameras = %d" %(p1.as_string(), p2.as_double(), p4.as_int64()))
    ps = client.get_paramslist()
    for p in ps:
        print(p.debug_string())
    # 6.等待关闭。
    cyber.shutdown()