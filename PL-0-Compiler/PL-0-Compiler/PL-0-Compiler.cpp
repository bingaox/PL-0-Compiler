// PL-0-Compiler.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <map>
#include "Lex.h"

#include "CommonLib.h"
using namespace std;
int main()
{
	vector<Word> WordList;
	Clex Lex;
	Lex.LexInit();
	Lex.DealSource(&WordList);



	

    return 0;
}

