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
    // Parte dati 
    int data;
    // Parte puntatori:
    // Figlio destro
	struct struttura* right; 
    // Figlio sinistro
    struct struttura* left;
}struttura;

typedef struttura* TreeNode; 
    



/**
 *              @author Yash Kumar 
 *                                @since 2002
 */    