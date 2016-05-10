#include "stdafx.h"
#include "CommonLib.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
string ReadFile(string SourceFileName)
{
	string Source = "";
	FILE *fp = fopen(SourceFileName.c_str(),"r");
	int i = 1;
	char Buffer[1];
	if (fp == NULL)
	{
		cout << "АЁСа" << endl;
		return "";
	}
	else
	{
		while (i == 1)
		{
			i = fread(Buffer, 1, 1, fp);
			if (i == 1)
				Source.push_back((char)Buffer[0]);

		}
	}
	return Source;
}

string ltrim(string str)
{
	if (str.empty())
	{
		return str;
	}

	string szTmp = "";
	int i;

	for (i = 0; str[i] <= 32 && i<str.length(); i++);

	for (; i<str.length(); i++)
	{
		szTmp.append(1, str[i]);
	}

	return szTmp;
}

string rtrim(string str)
{
	if (str.empty())
	{
		return str;
	}

	string szTmp = "";
	int i;
	for (i = str.length(); str[i] <= 32 && i >= 0; i--);

	for (int j = 0; j <= i; j++)
	{
		szTmp.append(1, str[j]);
	}

	return szTmp;
}
string trim(string str)
{
	return rtrim(ltrim(str));
}

string UpperCase(string str)
{
	string szTmp = str;

	for (int i = 0; i<szTmp.length(); i++)
	{
		if (szTmp[i] >= 'a' && szTmp[i] <= 'z')
		{
			szTmp[i] = szTmp[i] - ('a' - 'A');
		}
	}
	return szTmp;
}

string StrErase(string str, char c)
{
	string szTmp = "";
	int i;

	for (i = 0; i<str.length(); ++i)
	{
		if (str[i] != c)
		{
			szTmp.append(1, str[i]);
		}
	}

	return  szTmp;
}

void SetTbl(string szSource, map<string, int> &szTbl)
{
	string szTmp = "";
	int cnt = 0;
	for (int i = 0; i<szSource.length(); i++)
	{
		if (szSource[i] != '\n')
		{
			szTmp.append(1, szSource[i]);
		}
		else
		{
			if (szTmp.compare("") != 0)
			{
				szTbl.insert(pair<string, int>(szTmp, cnt));
				szTmp = "";
				cnt++;
			}
		}
	}
	if (szTmp.compare("") != 0)
		szTbl.insert(pair<string, int>(szTmp, cnt));
}