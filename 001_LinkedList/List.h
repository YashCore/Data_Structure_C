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
int changeBySurname(char surname[]);
int addSort(Node item);
int removeSort(int age);




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
		item->next= root;
		root=item;
	}
	return 0;
}


// Inserimento in coda
int addBottom(Node item){
	Node last= NULL;
	last=travers(); // last punta al ultimo elemento della lista

    last->next=item;
    return 0;
}


// Rimozione in testa
int removeHead(){
	if(root == NULL){
		return 1;
	}else{
		Node saveRef; //saveRef punta alla root precedente
		saveRef = root;
		root = root->next;
		free(saveRef);
	}
	return 0;
}


// Rimozione in coda
int removeBottom(){

	if(root == NULL){
		return 1;
	}else{
		Node secondlast;
		for(secondlast=root; secondlast->next->next != NULL; secondlast=secondlast->next){
			if(secondlast->next->next == NULL){
				free(secondlast->next);
				secondlast->next = NULL;
			}
		}
	}
	return 0;
}


int changeBySurname(char surname[]){
	if(root == NULL){
		return 1;
	}else{

		int choice = 0;
		char newData[24];
		Node current = NULL;
		current = root;

		while(!(strcmp((current->surname),surname))){
				current = current->next;
		}

		if(current->next != NULL){
			printf("\nWhat do you want to change?\n");
			printf("1. Name\n");
			printf("2. Surname\n");
			printf("3. Age\n");
			printf("4. Work\n");
			scanf("%d",&choice);

			switch(choice){
				case 1: printf("Enter new name:");
						gets(newData);
						strcpy((current->name),newData);
					break;

				case 2: printf("Enter new surname:");
						gets(newData);
						strcpy((current->surname),newData);
					break;

				case 3:	printf("Enter new age:");
						scanf("%d",&choice);
						current->age=choice;
						choice = 0;
					break;
				case 4: printf("Enter new work:");
						gets(newData);
						strcpy((current->work),newData);
						break;

				default: printf("Wrong choice!");
						 return 1;
			}

		}
	}
	return 0;
}


// Inserimento Lista Ordinata
int addSort(Node item){
	
	// CASO #1: Inserimento lista Vuota
	if(root == NULL){
		root = item;
		return 0; 
	}
	
	// CASO #2: Inserimento in Testa
	if(root->age < item->age){
		item->next = root;
		root = item;
		return 0;
	}	
	
	// Puntatore all elemento precedente a quello da inserire
	Node current = NULL;
	
	// CASO #3: Inserimento in Mezzo O Coda
	current = search(item);
	item->next = current->next;
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





int removeSort(int key){
	
	if(root == NULL)
		return -1;
		
		
	Node saveRef = NULL;		
	if(root->age == key){
		saveRef = root;
		root = root->next;
		free(saveRef);
		return 0;
	}	
	
	for(saveRef = root;(saveRef->next->next != NULL) && (saveRef->next->age < key); saveRef = saveRef->next);
	
	Node nodeDelete = saveRef->next;
	saveRef->next = nodeDelete->next;
	free(nodeDelete);
	return 0;
	
}




