#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
struct LineInfo
{
	int l_Row;  //�к�
	string l_FileName;
	LineInfo();
	//�������ڵ�Դ������ļ���
	LineInfo(int Row, string SourceFileName);
};
struct Word
{
	int w_Kind;  //��������
	string w_Content; //���ʱ�ע
	LineInfo w_LineInfo;  //�����к�
	Word();
	Word(int Kind, string Buffer, int Row, string SourceFileName);
	

};




