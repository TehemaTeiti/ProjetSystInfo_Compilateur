%{
	#include "rule.tab.h"
%}
PV			;
SEP			,
NOM			[a-zA-Z][a-zA-Z0-9_]*
%%

"int" 		{
				yylval.str = strdup(yytext);
				return tINT;
			}

"char" 		{
				yylval.str = strdup(yytext);
				return tCHAR;
			}

[0-9]+		{
				yylval.nb = atoi(yytext);
				return tNB;
			}

"main" 		return tMAIN;
\{ 				return tACCO;
\} 				return tACCF;
"const"			return tCONST;
"printf"		return tPRINTF;
"if"			return tIF;
"else"			return tELSE;
"while"			return tWHILE;
"for"			return tFOR;
"int *"			return tPINT;

\+				return tADD;
\-				return tSUB;
\*				return tMULT;
\/				return tDIV;
\=				return tEGAL;
\(				return tPARO;
\)				return tPARF;

"=="			return tEGEG;
"!="			return tDIFF;
"<"				return tINF;
"<="			return tINFEG;
">"				return tSUP;
">="			return tSUPEG;

{SEP}			return tSEP;
{PV}			return tPV;

{NOM}			{
					yylval.str = strdup(yytext);
					return tID;
				}

[ \t\n]			;
