import pyautogui
import time
import random

print("请输入's'开始")
a = input()
flag_A = 0
region = (0, 0, 1920, 1080)
while a == 's':
    while 1:
        start_time = time.time()
        try:
            A = pyautogui.locateCenterOnScreen("IMAGES/0.png", confidence=0.7)
            rad_num = random.randint(-20, 20)
            if A:
                print('A')
                if flag_A == 0:
                    pyautogui.click(A[0] + rad_num, A[1] + rad_num)
                    flag_A = 1
            B = pyautogui.locateCenterOnScreen("IMAGES/3.png", confidence=0.7)
            if B:
                flag_A = 0
                print('B')
                pyautogui.click(B[0] + rad_num, B[1] + rad_num)
                time.sleep(3)
                pyautogui.press('esc')
                end_time = time.time()
                print(f"the running time is: {end_time - start_time} s")
                time.sleep(2)
            C = pyautogui.locateCenterOnScreen("IMAGES/man.png", confidence=0.7)
            if C:
                flag_A = 0
                pyautogui.press('esc')
        except pyautogui.ImageNotFoundException:
            print("图片未找到")
            # 可以在这里添加相应的处理逻辑，比如等待一段时间后重新尝试
            time.sleep(2)
        print(flag_A)
