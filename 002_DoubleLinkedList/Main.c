#include "List.h" // Liste.h
#include <stdbool.h>



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
		printf("3.Show\n");
		printf("4.Exit\n");
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
                viewAll();
				break;
			case 4:
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
   
	fflush(stdin);
	printf("Enter name: "); // String
	gets(new->name);
	fflush(stdin);
	printf("Enter Surname: ");
	gets(new->surname); // String
	fflush(stdin);
	printf("Enter age\n");
	scanf("%d",&(new->age));
	fflush(stdin);
	printf("Enter your work"); // String
	gets(new->job);
	new->next = NULL;
    new->prev = NULL;

	fflush(stdin);
	printf("Where do You want to insert the element?(1.Head|2.Bottom|3.Ordered)\n");
	scanf("%d",&choice);

	switch(choice){
		case 1: esito = addHead(new);
			break;

		case 2: esito = addBottom(new);
			break;

		case 3: esito = addSort(new);
			break;	
	}
	return esito;
}

// Method to ask what to remove
int erase(){
	int choice = 0;
	int esito = 0;
	int key = 0;

	fflush(stdin);
	printf("Where do You want to remove the element?(1.Head|2.Bottom|3.Age)\n");
	scanf("%d",&choice);

	switch(choice){
		case 1: esito = removeHead();
			break;

		case 2: esito = removeBottom();
			break;

		case 3: 
			fflush(stdin);
			printf("Enter Age to be removed:\n");
			scanf("%d",&key);
			esito = removeSort(key);
			break;
	}
		return esito;
}

// Method to see all the content
void viewAll(){
	printf("%s",root->name);

	if(root == NULL)
		printf("\nNo User Registered.\n");
	else
		for(Node current = root; current != NULL; current = current->next){
			printf("\nName: %s\nSurname: %s\nAge: %d\nWork: %s\n",current->name, current->surname, current->age, current->job);}
}




