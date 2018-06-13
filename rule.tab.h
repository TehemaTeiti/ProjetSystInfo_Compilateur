/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_RULE_TAB_H_INCLUDED
# define YY_YY_RULE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tRETCHAR = 258,
    tINT = 259,
    tMAIN = 260,
    tACCO = 261,
    tACCF = 262,
    tCONST = 263,
    tID = 264,
    tADD = 265,
    tSUB = 266,
    tMULT = 267,
    tDIV = 268,
    tEGAL = 269,
    tPARO = 270,
    tPARF = 271,
    tSEP = 272,
    tPV = 273,
    tNB = 274,
    tPRINTF = 275,
    tPINT = 276,
    tIF = 277,
    tELSE = 278,
    tWHILE = 279,
    tFOR = 280,
    tCHAR = 281,
    tEGEG = 282,
    tDIFF = 283,
    tINF = 284,
    tINFEG = 285,
    tSUP = 286,
    tSUPEG = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "rule.y" /* yacc.c:1909  */

	int nb;
	char* str;

#line 92 "rule.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RULE_TAB_H_INCLUDED  */
