#include "Node.h" // include di dati(include di sistema) in Node.h


//  GESTIONE LOGICA DELLA LISTA

// Nodo Radice/testa
Node root = NULL;

// PROTOTIPI
Node create();
Node travers();
Node search(Node item);
int addHead(Node item);
int addBottom(Node item);
int removeHead();
int removeBottom();
int addSort(Node item);
Node search(Node item);
int removeSort(int key);


// malloc e retrun di un nuovo elemento 
Node create(){
	Node node =(Node)malloc(sizeof(struttura));
	return node;
}

// scorre tutta lista fino coda     
Node travers(){
	Node current = root;
	while (current->next != NULL)
		current = current->next; // si sposta di un elemento

	return current; // retitusce puntatore
}

// Inserimento in testa 
int addHead(Node item){

	// Verificare sempre se la lista sia vuota o no
	if(root == NULL)
		root=item;
	else{
        root->prev = item;
		item->next = root; 
        root=item;
	}
	return 0;
}

// Inserimento in coda 
int addBottom(Node item){
	Node last = NULL;
    
    if(root == NULL){
        root = item;
        return 0;
    }
    
	last = travers(); // last punta al ultimo elemento della lista
    
    last->next = item;
    item->prev = last; 
    return 0;
}

// Rimozione in testa 
int removeHead(){
	if(root == NULL){
		return 1;
	}
    
    root = root->next;
    free(root->prev);
    root->prev = NULL;
	
	return 0;
}

// Rimozione in coda 
int removeBottom(){

	if(root == NULL)
		return 1;
	
    Node last = travers();
    last->prev->next = NULL;
    free(last);
    
	return 0;
}

// Inserimento Ordinato
int addSort(Node item){
	
	// CASO #1: Inserimento lista Vuota
	if(root == NULL){
		root = item;
		return 0; 
	}
	
	// CASO #2: Inserimento in Testa
	if(root->age < item->age){
		item->next = root;
        root->prev = item;
		root = item;
		return 0;
	}	
	
	// Puntatore all elemento precedente a quello da inserire
	Node current = NULL;
    current = search(item);
	
        
	// CASO #3: Inserimento in Mezzo
	item->next = current->next;
    item->prev = current;
	current->next = item;
	return 0;	
}

// Ricerca nodo 
Node search(Node item){
	/*
	 * Restituisce il puntatore all'elemento precedente a
	 * quello da inserire;
	 *
	 * la Key dipende dal tipo di ordiantamento (campo)
	 */
	Node current = NULL;
	
	for(current = root; (current->next != NULL) && ((current->next->age) <(item->age)); current = current->next );
	
	return current; 
}


// Rimozione ordinata
int removeSort(int key){

	// CASO#1 : Rimozione Lista Vuota
	if(root == NULL)
		return -1;

	// CASO#2 : Rimozione testa 
	if(root->age == key){
		root=root->next;
		free(root->prev);
		return 0;
	}	

	// CASO#1 : Rimozione in mezzo o coda
	Node saveRef = root;

	for(saveRef = root; (saveRef->next != NULL) && (saveRef->age != key); saveRef = saveRef->next);

	if(saveRef->age == key){
		saveRef->prev->next = saveRef->next;
		free(saveRef);
		return 0;
	}

	return -2;

}





