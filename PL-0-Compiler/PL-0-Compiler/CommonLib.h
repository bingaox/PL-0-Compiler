#pragma once
#include "stdafx.h"
#include <string>
#include <map>
using namespace std;
string ReadFile(string SourceFileName);
string ltrim(string str);
string rtrim(string str);
string trim(string str);
string UpperCase(string str);
string StrErase(string str, char c);
void SetTbl(string szSource, map<string, int> &szTbl);