#include "Tree.h" // include di dati(include di sistema) in Node.h

// Serve come varivbile d'appaggio
TreeNode temp = NULL;

void doAdd();
void doMin();
void doMax();
void doPrint();
void doDelete();
void doSearch();
void doSuccsessor();
void doPredecessor();
void print_t(TreeNode tree);
int _print_t(TreeNode tree, int is_left, int offset, int depth, char s[20][255]);



int main(){

    int choice = 0;
    

    do
    {
        fflush(stdin);
        printf("1.Add\n2.Remove\n3.Max Value\n4.Min Value\n5.Search\n6.Successor\n7.Predecessor\n8.View\n9.Delete Tree\n10.Exit\n");
        scanf("%d",&choice);


        switch (choice){

            case 1: doAdd();
                break;
            
            case 2: doDelete();
                break;

            case 3: doMax();     
                break; 
    
            case 4: doMin();
                break;

            case 5: doSearch();
                break;        

            case 6: doSuccsessor();
                break;

            case 7: doPredecessor();
                break;    

            case 8: print_t(root);
                break;

            case 9: deleteTree(root);
                break;


            case 10:
                printf("Freeing Memory and Cosing....\n\n"); 
                break;    

            default:
                fflush(stdin);
                printf("Wrong choice!\n\n");
            
        }
    } while (choice !=10);
    
    free(temp);
    deleteTree(root);
    
    return 0;
}


/* For Clean Code */
void doAdd(){
    int data = 0;

    fflush(stdin);
    printf("Enter value: ");
    scanf("%d",&data);

    add(root,data);
}

void doMax(){
    int max = 0;

    if(root == NULL)
        printf("\nEmpty Tree!\n\n");
    else{
        temp = findMax(root);
        max = temp->data;
        printf("The maximum Value is: %d\n\n",max);
                    }
}

void doMin(){
    int min = 0;

    if(root == NULL)
        printf("\nEmpty Tree!\n\n");
    else{
        temp = findMin(root);
        min = temp->data;
        printf("The minumum Value is: %d\n\n",min);
    }
}

void doDelete(){
    int key = 0;

    fflush(stdin);
    printf("Enter key:\n");
    scanf("%d",&key);
    deleteNode(root,key);

}

void doSearch(){

    if(root == NULL){
        printf("Empty Tree!\n");
        return;
    }else{
        int data = 0;

        fflush(stdin);
        printf("Enter value: ");
        scanf("%d",&data);

        temp = search(root,data);
        if(temp != NULL)
            printf("Found: %d\n",temp->data);
        else
            printf("Element not found!\n");
    }    
}

void doSuccsessor(){
    
    if(root == NULL){
        printf("Empty Tree!\n");
        return;
    }else{
        int data = 0;

        fflush(stdin);
        printf("Enter value: ");
        scanf("%d",&data);

        temp = successor(temp);    
        if(temp == NULL)
            printf("No Succsessor\n");
        else        
            printf("Succsessor: %d\n",temp->data);
    }    
}

void doPredecessor(){

    if(root == NULL){
        printf("Empty Tree!\n");
        return;
    }else{
        int data = 0;

        fflush(stdin);
        printf("Enter value: ");
        scanf("%d",&data);

        temp = create(data);
        temp = findPredecessor(temp);
        if(temp == NULL)
            printf("No Prdecessor\n");
        else        
            printf("Predecessor: %d\n",temp->data);
    }    
}

void doPrint(){
    int choice = 0;


    do
    {
        printf("1.Tree\n2.Preorder\n3.Inorder\n4.PostOrder");


        switch (choice)
        {
        case 1:
            break;
        
        default:
            break;
        }
    } while (choice != 5);
    

}



/**
 * Methodo ricorsivo che stampa 
 * a grafico l'albero calcolando l'altezza
 * e la larghezza.
 * 
 * @param tree root del albero da stampare
 */
void print_t(TreeNode tree){
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);
    
    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

int _print_t(TreeNode tree, int is_left, int offset, int depth, char s[20][255]){
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->data);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}





/**
 *              @author Yash Kumar 
 *                                @since 2002
 */