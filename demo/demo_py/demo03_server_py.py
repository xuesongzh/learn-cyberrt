#!/usr/bin/env python3
"""  
    需求:实现请求响应
    实现:
        1.导包；
        2.初始化 cyber 框架；
        3.创建服务节点；
        4.创建服务方；
        5.处理请求；
        6.关闭。

"""
from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.addints_pb2 import AddInts_Request
from cyber.demo_base_proto.addints_pb2 import AddInts_Response

def cb(req):
    num1 = req.num1
    num2 = req.num2
    print("num1: %d, num2: %d" %(num1,num2))
    sum = num1 + num2
    response = AddInts_Response()
    response.sum = sum
    return response


if __name__ == "__main__":
    cyber.init()
    print("server.....")
    # 3.创建服务节点；
    server_node = cyber.Node("server_node")
    # 4.创建服务方；
    server = server_node.create_service("addints",AddInts_Request,AddInts_Response,cb)
    server_node.spin()
    # 5.处理请求；
    # 6.关闭。
    cyber.shutdown()