#!/usr/bin/env python3

'''  
    需求:实现消息发布方，发布数据

    实现:
        1.导包;
        2.初始化cyber框架;
        3.创建节点；
        4.创建发布方；
        5.组织并发送数据；
        6.等待关闭。

'''
from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.student_pb2 import Student
import time

def talk():
    # 3.创建节点；
    talker_node = cyber.Node("ergou_py")
    # 4.创建发布方；
    talker = talker_node.create_writer("chatter",Student)
    # 5.组织并发送数据；
    seq = 0
    while not cyber.is_shutdown():
        seq += 1
        print("send message %d" % seq)
        stu = Student()
        stu.name = "huluwa"
        stu.age = seq
        stu.height = 1.78
        stu.books.append("yuwen")
        stu.books.append("shuxue")
        stu.books.append("yingyu")


        talker.write(stu)
        time.sleep(1.0)

if __name__ == "__main__":
    cyber.init()
    #主逻辑封装进函数
    talk()
    cyber.shutdown()