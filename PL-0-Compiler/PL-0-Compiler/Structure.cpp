#include "stdafx.h"
#include "Structure.h"

Word::Word()
{
}

Word::Word(int Kind, string Buffer, int Row,string SourceFileName)
{
	w_Kind = Kind;
	w_Content = Buffer;
	w_LineInfo = LineInfo(Row, SourceFileName);
}

LineInfo::LineInfo()
{

}
LineInfo::LineInfo(int Row, string SourceFileName)
{
	l_Row = Row;
	l_FileName = SourceFileName;
}
