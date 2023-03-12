#!/usr/bin/env python3
'''  
    需求:订阅数据
    实现:
        1.导包；
        2.初始化 cyber 框架；
        3.创建订阅节点；
        4.创建订阅方；
        5.处理数据；
        6.等待关闭。

'''
from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.student_pb2 import Student

def cb(stu):
    # print(stu)
    print("name = %s age = %d height = %.2f" % (stu.name, stu.age, stu.height))
    for book in stu.books:
        print("book: %s" %book)
    print("-" * 80)

def listen():
    listener_node = cyber.Node("cuihua_py")
    listener = listener_node.create_reader("chatter",Student,cb)
    listener_node.spin()

if __name__ == "__main__":
    cyber.init()
    listen()
    cyber.shutdown()