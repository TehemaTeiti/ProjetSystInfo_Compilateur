%{
	#include <stdio.h>
	#include "tab_symb.c"
	#include "mem_instr.c"
	int yylex(void);
	void yyerror (char*);
	char * type;
%}

%union {
	int nb;
	char* str;
}

%token tRETCHAR tINT tMAIN tACCO tACCF tCONST tID tADD tSUB tMULT tDIV tEGAL tPARO tPARF tSEP tPV  tNB tPRINTF tPINT tIF tELSE tWHILE tFOR tCHAR tEGEG tDIFF tINF tINFEG tSUP tSUPEG

%left tADD tSUB
%left tMULT tDIV

%type <str> tINT tCHAR tID
%type <nb> tNB tIF tELSE tWHILE tPARO

%%

start : tINT tMAIN tPARO tPARF Body {affichage();};
Body : tACCO Instrs tACCF;
Instrs : Instr Instrs;
	| ;

Instr : Defs;	
	| Affect;
	| If;
	| tPRINTF tPARO Expr tPARF tPV;
	| tWHILE tPARO Expr tPARF 	{add_mem("LOAD", 0, get_index());
							 	 add_mem("JMPC", -1, 0);
							 	 $1 = idx_mem-1;}
		Body					{add_mem("JMP", $1-1, 0);
								 patch($1,idx_mem);};

If : tIF tPARO Expr tPARF 	{add_mem("LOAD", 0, get_index());
							 add_mem("JMPC", -1, 0);
							 $1 = idx_mem-1;} 
		Body 				{ patch($1, idx_mem); }
		tELSE 				{ add_mem("JMP", -1, 0);
							  patch($1, idx_mem);
							  $8 = idx_mem-1;} 
		Body 				{ patch($8, idx_mem); };
	| tIF tPARO Expr tPARF 	{add_mem("LOAD", 0, get_index());
							add_mem("JMPC", -1, 0);
							$1 = idx_mem-1;} 
		  Body 				{patch($1, idx_mem);};

Type : tINT { type = $1; };
	| tCHAR { type = $1; };

Defs : Type tID Defs tPV 		{add($2,type,0,0);}; 
	| tCONST Type tID Defs tPV 	{add($3,type,0,0);}; 
	| tSEP tID Defs 			{add($2,type,0,0);};
	| ;

Affect : tID tEGAL Expr tPV 	{update($1, 1, 0);
								 add_mem("LOAD", 0, get_index());
					  			 add_mem("STORE", find($1,0), 0);};

Expr : tNB {add_mem("AFC", 0, $1);
			add_mem("STORE", new_tmp(), 0);};

	| tID			{ add_mem("LOAD", 0, find($1,0));
					  add_mem("STORE", new_tmp(), 0);
					  };

	| Expr tADD Expr {add_mem("LOAD", 1, get_index());
					  add_mem("LOAD", 0, get_index());
					  add_mem("ADD", 0, 1);
					  add_mem("STORE", new_tmp(), 0);};

	| Expr tSUB Expr {add_mem("LOAD", 1, get_index());
					  add_mem("LOAD", 0, get_index());
					  add_mem("SOU", 0, 1);
					  add_mem("STORE", new_tmp(), 0);};

	| Expr tMULT Expr {add_mem("LOAD", 1, get_index());
					  add_mem("LOAD", 0, get_index());
					  add_mem("MUL", 0, 1);
					  add_mem("STORE", new_tmp(), 0);};

	| Expr tDIV Expr {add_mem("LOAD", 1, get_index());
					  add_mem("LOAD", 0, get_index());
					  add_mem("DIV", 0, 1);
					  add_mem("STORE", new_tmp(), 0);};

	| Expr tEGEG Expr 	{ add_mem("LOAD", 1, get_index());
						  add_mem("LOAD", 0, get_index());
						  add_mem("EQU", 0, 1);
						  add_mem("STORE", new_tmp(), 0);
						};

	| Expr tDIFF Expr	{ add_mem("LOAD", 1, get_index());
						  add_mem("LOAD", 0, get_index());
						  add_mem("EQU", 0, 1);
						  add_mem("STORE", new_tmp(), 0);
						};

	| Expr tINF Expr	{ add_mem("LOAD", 1, get_index());
						  add_mem("LOAD", 0, get_index());
						  add_mem("INF", 0, 1);
						  add_mem("STORE", new_tmp(), 0);
						};

	| Expr tINFEG Expr	{ add_mem("LOAD", 1, get_index());
						  add_mem("LOAD", 0, get_index());
						  add_mem("INFE", 0, 1);
						  add_mem("STORE", new_tmp(), 0);
						};

	| Expr tSUP Expr	{ add_mem("LOAD", 1, get_index());
						  add_mem("LOAD", 0, get_index());
						  add_mem("SUP", 0, 1);
						  add_mem("STORE", new_tmp(), 0);
						};

	| Expr tSUPEG Expr	{ add_mem("LOAD", 1, get_index());
						  add_mem("LOAD", 0, get_index());
						  add_mem("SUPE", 0, 1);
						  add_mem("STORE", new_tmp(), 0);
						};

	| tPARO Expr tPARF	;

%%
int main() {
	yyparse();
	init_mem();	
}

