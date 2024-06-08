#include <Windows.h>
#include <bits/stdc++.h>

using std::string;

void MyOpenFile(string pth)
{
	char dirp[260]="";
	GetEnvironmentVariable("USERPROFILE",dirp,260);

	std::string path=pth;
	std::string::size_type iPos=path.find_last_of('\\')+1;
	std::string filename=path.substr(iPos,path.length()-iPos);
	path=filename;
	iPos=path.find_last_of('.')+1;
	filename=path.substr(iPos,path.length()-iPos);

	char app[260]="";
	if(filename=="ppt"||filename=="pptx") strcpy(app,"powerpnt.exe");
	else if(filename=="doc"||filename=="docx") strcpy(app,"winword.exe");
	else if(filename=="xls"||filename=="xlsx") strcpy(app,"excel.exe");
	else if(filename=="pdf") strcpy(app,"msedge.exe");

	pth="\""+pth+"\"";

	ShellExecute(NULL,"open",app,TEXT(pth.c_str()),dirp,SW_SHOWMAXIMIZED);
}

void CpyFile(string pth)
{
	char dirp[260]="";
	GetEnvironmentVariable("USERPROFILE",dirp,260);
	strcat(dirp,"\\collect\\");

	std::string path=pth;
	std::string::size_type iPos=path.find_last_of('\\')+1;
	std::string filename=path.substr(iPos,path.length()-iPos);
//		std::cout<<filename<<std::endl;

	strcat(dirp,filename.c_str());

//		std::cout<<dirp<<std::endl;
//		std::cout<<TEXT(argv[i])<<' '<<TEXT(dirp)<<std::endl;

	bool t=CopyFile(TEXT(pth.c_str()),TEXT(dirp),FALSE);
//		if(t==0) MessageBox(NULL,"ERROR!!","???",MB_OK);
}

int main(int argc,char** argv)
{
	if(argc==1) MessageBox(NULL,TEXT("Wrong!"),"Aaaa!",MB_OK),exit(1);
	string cur="";
	for(int i=1; i<argc; i++)
	{
		if(strlen(argv[i])>=2&&argv[i][1]==':')
		{
			if(cur!="") MyOpenFile(cur);
			cur=argv[i];
		}
		else if(cur.size()>=2&&cur[1]==':')
			cur=cur+" "+argv[i];
	}
	if(cur!="") MyOpenFile(cur);
	cur="";
	for(int i=1; i<argc; i++)
	{
		if(strlen(argv[i])>=2&&argv[i][1]==':')
		{
			if(cur!="") CpyFile(cur);
			cur=argv[i];
		}
		else if(cur.size()>=2&&cur[1]==':')
			cur=cur+" "+argv[i];
	}
	if(cur!="") CpyFile(cur);
	return 0;
}