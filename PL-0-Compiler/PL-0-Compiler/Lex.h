#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>

#include "Structure.h"
using namespace std;

class Clex
{
public:
	Clex();
	~Clex();
	bool DealSource(vector<Word> *WordList);	//生成单词流函数
	void SetKeyWord(string Str);				//设置关键字表函数
	void SetLexTable(string Str);				//设置转换表函数
	void SetFileName(string Str);				//设置源文件程序名函数
	void LexInit();

private:
	int LexTable[20][130];  //存放状态表
	string Source;			//源文件的单词流
	string SourceFileName;	//源文件名
	string Buffer;			//单词缓冲区
	int Row;				//当前行号
	int NonTerminal;		//当前非终结符的状态编号
	int Position;				//源代码当前读取位置
	vector<Word> *t_WordList;  //单词流
	bool Process(int Tag);	//词法分析处理
	map<string, int> KeyWordTable;
	void AddWord(const int Kind,const string Content,const int Row);		//记录单词函数
	void AddWord(const int Kind, const int Content, const int Row);		//记录单词函数
	bool SearchWord(string KeyWord, int &Position);						//搜索关键字
	void BufferBack();													//单词缓冲区回退

	
	
	
};

