#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tab_symb.h"
#define SIZE 100
struct tab_symbole tab[SIZE];
int idx = 0;

/*int main() {
	struct tab_symbole tab[SIZE];
	int cpt = 0;
	add(tab, "i", 'i', 0, 0, &cpt);
	add(tab, "j", 'i', 0, 1, &cpt);
	add(tab, "k", 'i', 1, 0, &cpt);
	affichage(tab, &cpt);
	
}*/

void add(char * id, char * type, int init, int depth) {
	// vérification dépassement taille
	if (idx >= SIZE) {	
		printf("error : stackoverflow\n");
		exit(1);
	}

	// vérification d'existence
	if (find(id, depth) != -1) {
		printf("error : %s declared more than once\n", id);
		//exit(2);
	}
	
	// add
	strcpy((tab+idx)->id,id);
	strcpy((tab+idx)->type,type);
	(tab+idx)->init = init;
	(tab+idx)->depth = depth;
	idx++;
}


void update(char * id, int init, int depth) {
	int i;
	i = find(id, depth);

	// si on trouve la variable dans la table des symboles, on modifie sa valeur "init"
	if (i != -1) {
		(tab+i)->init = init;
	}

}

void affichage() {
	int i;
	printf("|ID\t|Type\t|Init\t|Depth\t|\n");	
	for (i=0; i < idx ; i++) {
		printf("|%s\t|%s\t|%d\t|%d\t|\n", (tab+i)->id, (tab+i)->type, (tab+i)->init, (tab+i)->depth);
	}
}

/*
	Retourne -1 si variable n'existe pas dans la table des symboles, son indice sinon
*/
int find(char * id, int depth) {
	int i;	
	for (i=0; i < idx ; i++) {
		if ((strcmp((tab+i)->id,id) == 0) && ((tab+i)->depth == depth)) {
			return i;
		}
	}
	return -1;
}

/*
	Ajoute une nouvelle variable temporaire dans la table des symboles
*/
int new_tmp() {
	int i;
	i = idx;
	strcpy((tab+idx)->id, "#");
	idx++;
	return i;
}

/*
	Renvoie l'indice du dernier élément de la table et décrémente l'index
*/
int get_index() {
	idx--;
	return idx;
}
