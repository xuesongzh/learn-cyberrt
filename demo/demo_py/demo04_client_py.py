#!/usr/bin/env python3
"""  
    需求:发送两个数字到服务端，并处理响应
    实现:
        1.导包；
        2.初始化；
        3.创建节点；
        4.创建客户端；
        5.发送数据处理响应；
        6.等待关闭。

"""

from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.addints_pb2 import AddInts_Request
from cyber.demo_base_proto.addints_pb2 import AddInts_Response
import sys

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("please input two args:")
        sys.exit(1)
    cyber.init()
    print("client...... ")
    # 3.创建节点；
    client_node = cyber.Node("client_node")
    # 4.创建客户端；
    client = client_node.create_client("addints",AddInts_Request,AddInts_Response)
    # 5.发送数据处理响应；
    req = AddInts_Request()
    req.num1 = int(sys.argv[1])
    req.num2 = int(sys.argv[2])
    response = client.send_request(req)
    print("response sum = %d" %response.sum)
    # 6.等待关闭。
    cyber.shutdown()