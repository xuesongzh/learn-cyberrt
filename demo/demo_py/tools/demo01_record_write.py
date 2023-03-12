#!/usr/bin/env python3

"""  
    需求：将 student 消息写入到磁盘文件
    实现：
        1.创建写出对象；
        2.设置写出参数；
        3.打开文件流；
        4.组织消息；
        5.写出消息；
        6.关闭文件流。


"""

from cyber.python.cyber_py3 import cyber
from cyber.python.cyber_py3 import record
from cyber.demo_base_proto.student_pb2 import Student

if __name__ == "__main__":
    cyber.init()
    print("record write ....")
    # 1.创建写出对象；
    writer = record.RecordWriter()
    # 2.设置写出参数；
    writer.set_size_fileseg(0)
    writer.set_intervaltime_fileseg(0)
    # 3.打开文件流；
    writer.open("/apollo/cyber/demo_py/tools/mytest_py.record")
    # 4.组织消息；
    stu = Student()
    stu.name = "haha"
    stu.height = 1.78
    stu.books.append("yuwen")
    stu.books.append("shuxue")
    stu.books.append("yingyu")
    print("full name:%s" %stu.DESCRIPTOR.full_name)
    channel = "chatter_py"
    writer.write_channel(channel,"cyber.demo_base_proto.Student","test....")
    for seq in range(20):
        stu.age = seq
        writer.write_message(channel,stu.SerializeToString(),seq)

    # 5.写出消息；
    # 6.关闭文件流。
    writer.close()