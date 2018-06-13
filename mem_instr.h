struct tab_mem {
	char id[16]; // identifiant de l'instruction assembleur
	int param0; // identifiant de l'instruction assembleur
	int param1; // identifiant de l'instruction assembleur
};


void init_mem();
void add_mem(char* id, int param0, int param1);
int get_index_mem();
void patch(int instr, int val);
