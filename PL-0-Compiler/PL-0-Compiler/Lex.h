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
	bool DealSource(vector<Word> *WordList);	//���ɵ���������
	void SetKeyWord(string Str);				//���ùؼ��ֱ���
	void SetLexTable(string Str);				//����ת������
	void SetFileName(string Str);				//����Դ�ļ�����������
	void LexInit();

private:
	int LexTable[20][130];  //���״̬��
	string Source;			//Դ�ļ��ĵ�����
	string SourceFileName;	//Դ�ļ���
	string Buffer;			//���ʻ�����
	int Row;				//��ǰ�к�
	int NonTerminal;		//��ǰ���ս����״̬���
	int Position;				//Դ���뵱ǰ��ȡλ��
	vector<Word> *t_WordList;  //������
	bool Process(int Tag);	//�ʷ���������
	map<string, int> KeyWordTable;
	void AddWord(const int Kind,const string Content,const int Row);		//��¼���ʺ���
	void AddWord(const int Kind, const int Content, const int Row);		//��¼���ʺ���
	bool SearchWord(string KeyWord, int &Position);						//�����ؼ���
	void BufferBack();													//���ʻ���������

	
	
	
};

