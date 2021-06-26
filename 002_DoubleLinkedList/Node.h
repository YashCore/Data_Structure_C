#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
 * Definizione della struttura fisica
 * di ogni nodo della lista
 *
 * Da modificare (eventualmente) a seconda dell'app
 */
typedef struct struttura{
	char name[24];
	char surname[24];
	int age;
	char job[24];
	struct struttura* next; // CAMPO OBLIGATORIO PER LE LISTE
    struct struttura* prev;
}struttura;

typedef struttura* Node; // Rimane da non modificare viene utilizzata in List.h
    