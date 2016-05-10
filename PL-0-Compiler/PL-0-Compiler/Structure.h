#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
struct LineInfo
{
	int l_Row;  //行号
	string l_FileName;
	LineInfo();
	//单词所在的源程序的文件名
	LineInfo(int Row, string SourceFileName);
};
struct Word
{
	int w_Kind;  //单词种类
	string w_Content; //单词备注
	LineInfo w_LineInfo;  //单词行号
	Word();
	Word(int Kind, string Buffer, int Row, string SourceFileName);
	

};




