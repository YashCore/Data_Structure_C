#include "List.h" // Liste.h
#include <stdbool.h>



/*
 *1. Inserire un nuovo elemento (scegliere se in testa o in coda)
 *2. eliminare un elemento (scegliere se in testa o in coda)
 *3. Modificare un elemento (tramite il cognome)
 *4. Vedere tutti gli elementi
 *5. Fine
 */


// Prototipi
int add();
int erase();
void viewAll();



int main(){
	int choice=0;
	int esito=0;
	char str[24];


	do{
		printf("1.Add\n");
		printf("2.Erase\n");
		printf("3.Change\n");
		printf("4.Show\n");
		printf("5.Exit\n");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				 esito=add();
				 if(esito!=0)
					 printf("Entry Error!\n\n");
				 else
					 printf("Successfully Added!\n\n");
				break;

			case 2:
				esito = erase();
				if(esito != 0)
					printf("Remove Error!\n\n");
				else
					printf("Successfully Removed!\n\n");
				break;

			case 3:
				printf("Enter your surname:\n\n");
				gets(str);
				esito = changeBySurname(str);
				if(esito != 0)
					printf("Changing Error!\n\n");
				else
					printf("Successfully changed!\n\n");
				break;
			case 4:
				viewAll();
				break;
			case 5:
				printf("Thanks for testing the program");
				break;

			default: printf("Wrong choice");

		}
	}while(choice != 5);


	return 0;

}

// Method to add a new user
int add(){
	int choice=0;
	int esito=0;
	Node new =NULL;
	new = create(); // invoca la malloc per il nuovo elemento
	printf("")
	printf("Enter name "); // String
	gets(new->name);
	printf("Enter Surname");
	gets(new->surname); // String
	printf("Enter age\n");
	scanf("%d",&(new->age));
	printf("Enter your work"); // String
	gets(new->work);
	new->next=NULL;

	printf("Where do You want to insert the element?(1.Head|2.Bottom)\n");
	scanf("%d",&choice);

	switch(choice){
		case 1: esito = addHead(new);
			break;

		case 2: esito = addBottom(new);
			break;
	}
	return esito;
}

// Method to ask what to remove
int erase(){
	int choice=0;
	int esito=0;

	printf("Where do You want to remove the element?(1.Head|2.Bottom)\n");
	scanf("%d",&choice);

	switch(choice){
		case 1: esito = removeHead();
			break;

		case 2: esito = removeBottom();
			break;
		}
		return esito;
}

// Method to see all the content
void viewAll(){

	if(root == NULL)
		printf("Empty list\n");
	else{
		Node current=NULL;

		for(current=root; current->next!=NULL; current=current->next){
			// le printf cambiano a seconda della struttura fisica
			 //printf("User :%s\n %s\n %s\n %d\n %s\n-----\n", (current->name), (current->surname), (current->age), (current->work));
			 printf("User :%s\n",(current->name));
		}
	}
}




