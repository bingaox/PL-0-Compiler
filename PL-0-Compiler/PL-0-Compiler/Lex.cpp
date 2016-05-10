#include "stdafx.h"
#include "Structure.h"
#include "Lex.h"
#include <io.h>
#include <string.h>
#include "CommonLib.h"
using namespace std;

Clex::Clex()
{
}

Clex::~Clex()
{
}

bool Clex::DealSource(vector<Word> *WordList)
{
	bool Tag = true;	//状态是否合法
	Position = 0;		//当前读取的源文件位置
	Row = 1;			//行号初始化为0
	NonTerminal = 0;    //当前非终结符状态为0
	int TmpPosition = 0;
	t_WordList = WordList;

	Source = ReadFile("Source.txt");
	Source.push_back(' ');
	Buffer = "";
	WordList->clear();

	while (Position < Source.length() && Tag)
	{
		if (Source[Position] == '\n'&&TmpPosition != Position)
		{
			Row++;
			TmpPosition = Position;
		}

		Buffer.push_back(Source[Position]);

		Tag = Process(LexTable[NonTerminal][int(Source[Position]) < 128 ? Source[Position] : 128]);

		if (!Tag)
		{
			printf("错误！");
			return false;
		}

		Position++;


	}
	return Tag;

}

void Clex::SetKeyWord(string str)
{
	string szTmp = "";
	int cnt = 0;
	for (int i = 0; i<str.length(); i++)
	{
		if (str[i] != '\n')
		{
			szTmp.append(1, str[i]);
		}
		else
		{
			if (szTmp.compare("") != 0)
			{
				KeyWordTable.insert(pair<string, int>(szTmp, cnt));
				szTmp = "";
				cnt++;
			}
		}
	}
	if (szTmp.compare("") != 0)
		KeyWordTable.insert(pair<string, int>(szTmp, cnt));
}

void Clex::LexInit()
{
	Source = "";
	SetLexTable(ReadFile("lex.txt"));
	SetKeyWord(ReadFile("keyWord.txt"));
}

bool Clex::Process(int Tag)
{
	int Tmp = 0;
	cout << Buffer;
	if (Tag == -99)
	{
		return false;
	}

	if (Tag < 0)
	{
		BufferBack();	//退一格
		Buffer = trim(Buffer);
		cout << Buffer;
		t_WordList->push_back(Word(-Tag, Buffer, Row,SourceFileName));
		Buffer = "";
		NonTerminal = 0;
		return true;
	}

	else
	{
		NonTerminal = Tag;
	}

	return true;

	
}

bool Clex::SearchWord(string KeyWord, int &Position)
{
	map<string, int>::iterator It = KeyWordTable.find(KeyWord);
	if (It != KeyWordTable.end())
	{
		Position = It->second;
		return true;
	}
	return false;
}


void Clex::BufferBack()
{
	Buffer.erase(Buffer.end() - 1);
	Position--;
}

void Clex::AddWord(int Kind, string Content, int Row)
{

}
void Clex::AddWord(int Kind, const int Content, const int Row)
{

}

void Clex::SetLexTable(string str)
{
	int iRow = 0;
	int iCol = 0;
	int iTmp = 0;
	str = StrErase(str, '\n');

	for (iRow = 0; iRow <= 19; iRow++)
	{
		for (iCol = 0; iCol <= 127; iCol++)
		{
			LexTable[iRow][iCol] = atoi(str.substr(iTmp, 3).c_str());
			iTmp = iTmp + 3;
		}
	}
}