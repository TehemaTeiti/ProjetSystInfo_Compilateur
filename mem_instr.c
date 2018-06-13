#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem_instr.h"
#define SIZE 100

struct tab_mem mem[SIZE];
int idx_mem = 0;

void init_mem() {
	FILE *f;
	int i;

	// création/ouverture du fichier
	if ((f = fopen("./mem.txt", "w")) == NULL) {
		perror("error : can't open the mem file");
		exit(-1);
	}
	
	// TODO écriture dans le fichier
	for (i = 0; i < idx_mem; i++) {
		fprintf(f, "%s %d %d\n", (mem+i)->id, (mem+i)->param0, (mem+i)->param1);
	}	

	// fermeture du fichier
	if (fclose(f) == EOF) {
		perror("error : can't close the meme file => EOF");
		exit(-1);
	}
}

void add_mem(char* id, int param0, int param1) {
	strcpy((mem+idx_mem)->id, id);
	(mem+idx_mem)->param0 = param0;
	(mem+idx_mem)->param1 = param1;
	idx_mem++;
}

int get_index_mem() {
	return idx_mem;
}

void patch(int instr, int val) {
	(mem+instr)->param0 = val;
}
