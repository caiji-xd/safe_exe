#include <bits/stdc++.h>
#include <windows.h>
#include <string>
using namespace std;
#define key_down(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)//��ⰴ������

HWND hwnd2=GetForegroundWindow();
HWND hwnd;
int jg=10;
bool xhzd=false;

void gotoxy(int x, int y) {
	COORD pos = {y,x};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��

}
void SetColorAndBackground(int ForgC, int BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void print(string a,int i,int j,int color1=0,int color2=15) {
	int i2;
	gotoxy(i,j);
	SetColorAndBackground(color1, color2);
	printf(a.c_str());
}
void HideTheCursor() {
	CONSOLE_CURSOR_INFO cciCursor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if(GetConsoleCursorInfo(hStdOut, &cciCursor)) {
		cciCursor.bVisible = FALSE;
		SetConsoleCursorInfo(hStdOut, &cciCursor);
	}
}
string its(int a){ 
	return to_string(a);
}
string bts(bool a){
	if(a)return "true";
	else return "false";
}

int main() {
	HideTheCursor();
	print("=================================================",0,0,15,0);
	print("�� \"�������\"��\"С����\" ���ƴ����ö�����",1,0,4,0);
	print("by caiji_233",2,0,7,0);
	print("=================================================",3,0,15,0);
	print("�Ҽ����������ö����ڣ�",6,0,11,0);
	while(1) {
		if(key_down(VK_RBUTTON)) {
			hwnd=GetForegroundWindow();
			SetWindowPos(hwnd2,HWND_TOPMOST, 0, 0, 0, 0,
			             SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOSIZE);
			SetWindowPos(hwnd2,HWND_NOTOPMOST, 0, 0, 0, 0,
			             SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOSIZE);
			break;
		}
		Sleep(50);
	}
	cout<<hwnd<<endl;
	print("���óɹ���",7,0,11,0);
	print("����",9,0,4,0);
	print("=================================================",10,0,15,0);
	print("Ctrl+win �����ö�",11,0,15,0);
	print("Shitf+Ctrl+win ѭ���ö������ε���رգ�",12,0,15,0);
	print("Shift+Ctrl+\'w\' ����ѭ���ö��������λ0.1s)",13,0,15,0);
	print("Shift+Ctrl+\'s\' ����ѭ���ö��������λ0.1s)",14,0,15,0);
	print("=================================================",15,0,15,0);
	print("ѭ���ö������"+its(jg/10)+"."+its(jg%10)+" s",16,0,4,0);
	print("ѭ���ö���"+bts(xhzd)+"  ",17,0,4,0);
	while(1) {
		HideTheCursor();
		if(key_down(VK_LSHIFT)&&key_down(VK_CONTROL)&&key_down(VK_LWIN)) {
			xhzd=true;
			MessageBeep(64);
		} else if(key_down(VK_CONTROL)&&key_down(VK_LWIN)) {
			SetWindowPos(hwnd,HWND_TOPMOST, 0, 0, 0, 0,
			             SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOSIZE);
			SetWindowPos(hwnd,HWND_NOTOPMOST, 0, 0, 0, 0,
			             SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOSIZE);
		} else if(key_down(VK_LSHIFT)&&key_down(VK_CONTROL)&&key_down('W')) {
			jg++;
		} else if(key_down(VK_LSHIFT)&&key_down(VK_CONTROL)&&key_down('S')) {
			if(jg>0)jg--;
		}
		if(xhzd) {
			Sleep(500);
			int t=0;
			while(1) {
				if(t%(jg*5)==0) {
					SetWindowPos(hwnd,HWND_TOPMOST, 0, 0, 0, 0,
					             SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOSIZE);
				}
				if(key_down(VK_LSHIFT)&&key_down(VK_CONTROL)&&key_down(VK_LWIN)) {
					xhzd=false;
					SetWindowPos(hwnd,HWND_NOTOPMOST, 0, 0, 0, 0,
					             SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOSIZE);
					MessageBeep(64);
					SetWindowPos(hwnd2,HWND_TOPMOST, 0, 0, 0, 0,
					             SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOSIZE);
					SetWindowPos(hwnd2,HWND_NOTOPMOST, 0, 0, 0, 0,
					             SWP_NOMOVE | SWP_DRAWFRAME | SWP_NOSIZE);
					Sleep(500);
					break;
				} else if(key_down(VK_LSHIFT)&&key_down(VK_CONTROL)&&key_down('W')) {
					jg++;
				} else if(key_down(VK_LSHIFT)&&key_down(VK_CONTROL)&&key_down('S')) {
					if(jg>1)jg--;
				}
				t++;
				Sleep(20);
				print("ѭ���ö������"+its(jg/10)+"."+its(jg%10)+" s",16,0,4,0);
				print("ѭ���ö���"+bts(xhzd)+"  ",17,0,4,0);
			}
		}
		print("ѭ���ö������"+its(jg/10)+"."+its(jg%10)+" s",16,0,4,0);
		print("ѭ���ö���"+bts(xhzd)+"  ",17,0,4,0);
		Sleep(20);
	}
}

