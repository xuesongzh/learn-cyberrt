#!/usr/bin/env python3
"""  
    需求：将 student 消息写入到磁盘文件
    实现：
        1.创建读取对象；
        2.读消息；
        3.关闭文件流。


"""
from cyber.python.cyber_py3 import cyber
from cyber.python.cyber_py3 import record
from cyber.demo_base_proto.student_pb2 import Student

if __name__ == "__main__":
    cyber.init()
    print("record read ....")
    reader = record.RecordReader("/apollo/cyber/demo_py/tools/mytest_py.record")
    msgs = reader.read_messages()
    count = 0
    for msg in msgs:
        count += 1
        print("=" * 20)
        print("data NO.%d" % count)
        print("channel_name:%s" % msg[0])
        print("msg num %d" % reader.get_messagenumber(msg[0]))
        print("data:%s" % msg[1])
        print("data type:%s" % msg[2])
        print("time %d" % msg[3])

        msg_new = Student()
        msg_new.ParseFromString(msg[1])
        print(msg_new)