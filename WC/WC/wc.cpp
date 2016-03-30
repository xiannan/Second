#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<windows.h>
#include<ctime>
using namespace std;


int wordCount(fstream &file)
{
	int count=0;
	string c;
	while(file>>c)
	{
		if(c!=" " && c!=">" && c!="<" && c!=";")
			count++;
	}
	return count;
}
int charCount(fstream &file)
{
	int count=0;
	char c;
	while(file>>c)
	{
		count++;
	}
	return count;
}
int lineCount(fstream &file)
{
	int count=0;
	char lines[512];
	while(file.getline(lines,512,'\n'))
	{
		count++;
	}
	return count;
}
void initCmd(int argc,char *argv[])//初始化参数
{
	fstream file;
	for(int i=1;i<argc;i++)
	{
		string s(argv[argc--]);
		if(s=="-c")
		{
			charCount(file);
		}
		else if(s=="-w")
		{
			wordCount(file);
		}
		else if(s=="-l")
		{
			lineCount(file);
		}
		else
		{
			file.open(s,ios::in);
			if(!file.good())
			{
				cout<<"文件打开失败";
			}
		}
	}
}
int main(int argc,char *argv[])
{
	initCmd(argc,argv);
}