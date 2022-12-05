#include<stdio.h>
#include<stdlib.h>

struct nodo{
	struct nodo* hijo_izq;
	struct nodo* hijo_der;
	int dato;
};

struct nodo* nuevoNodo(int dato){
	size_t tam_nodo = sizeof(struct nodo);
	struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);
	nuevo_nodo->dato = dato;
	nuevo_nodo->hijo_izq = NULL;
	nuevo_nodo->hijo_der = NULL;

	return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
	if(dato > nd->dato){
		if(nd->hijo_der == NULL){
			nd->hijo_der = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_der, dato);
		}
	}else{
		if(nd->hijo_izq == NULL){
			nd->hijo_izq = nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_izq, dato);
		}
	}
}

int lvl = 0;
void buscar(struct nodo* nd, int n){
	lvl++;
	if(n == nd->dato){
		printf("El numero %d fue encontrado en el nivel %d\n", n, lvl);
	}else if(n < nd->dato && nd->hijo_izq != NULL){
		buscar(nd->hijo_izq, n);
	}else if(n > nd->dato && nd->hijo_der != NULL){
		buscar(nd->hijo_der, n);
	}else{
		printf("El numero %d no se encontró\n", n);
	}
}

int main(){
	int n = 0;
	struct nodo* raiz = NULL;
	raiz = nuevoNodo(6);
	insertarNodo(raiz, 5);
	insertarNodo(raiz, 11);
	insertarNodo(raiz, 4);
	insertarNodo(raiz, 8);
	insertarNodo(raiz, 12);
	insertarNodo(raiz, 3);
	insertarNodo(raiz, 9);
	insertarNodo(raiz, 21);

	printf("Que numero desea buscar? ");
	scanf("%d", &n);

	buscar(raiz, n);

	return 0;
}