struct tab_symbole {
	char id[16]; // identifiant de la variable
	char type[10]; // type de la variable
	int init; // 0 si non initialisé, autre sinon
	int depth; // profondeur qui commence à 1
};

void add(char * id, char * type, int init, int depth);
void update(char * id, int init, int depth);
void affichage();
int find(char * id, int depth);
int new_tmp();
int get_index();
