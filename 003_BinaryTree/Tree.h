#include "Node.h" // include di dati(include di sistema) in Node.h


// Empyt tree root
TreeNode root = NULL;


//---------------PROTOTIPI---------------
TreeNode create(int key);                          // Ok
void deleteTree(TreeNode node);                    // Ok
TreeNode findMin(TreeNode node);                   // Ok
TreeNode findMax(TreeNode node);                   // Ok 
void printInorder(TreeNode node);                  // Ok 
int add(TreeNode parent, int key);                 // Ok
void printPreorder(TreeNode node);                 // Ok
void printPostorder(TreeNode node);                // Ok
TreeNode successor(TreeNode successor);            // Ok comment to set
TreeNode search(TreeNode parent, int key);         // Ok
TreeNode findPredecessor(TreeNode parent);         // Ok comment need 
TreeNode deleteNode(TreeNode  parent, int key);    // Ok


void printPostorder(TreeNode node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    printf("%d ", node->data);
}
 

void printInorder(TreeNode node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder(node->right);
}
 

void printPreorder(TreeNode node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    printf("%d ", node->data);
 
    /* then recur on left sutree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}


/**
 * Malloc di nuovo nodo
 * Makes NULL all the pointers
 * 
 * @param data integer to be inserted
 * @return new TreeNode
*/
TreeNode create(int key){
    TreeNode node = (TreeNode)malloc(sizeof(struttura));
    node->left = NULL;
    node->right = NULL;
    node->data = key;
	return node;
}


/**
 * Metodo che scorre dalla  
 * root fino alla foglia più 
 * destra.
 * 
 * @param node è la root del albero di cui  
 *              dobbiamo trovare il massimo
 * @return della foglia 
*/
TreeNode findMax(TreeNode node){

    TreeNode parent = root; 
    // Scorre verso il figlio di destra fino a arrivare alla foglia
    while (parent->right != NULL)
        parent = parent->right; // Si sposta uno a uno verso destra
    
    return parent;
}


/** 
 * Metodo che scorre dalla  
 * root fino alla foglia più 
 * sinistra.
 * 
 * @param node è la root del albero di cui 
 *              dobbiamo trovare il minimo
 * @return della foglia 
*/
TreeNode findMin(TreeNode node){

    TreeNode parent = root; 
    // Scorre verso il figlio di sinistra fino a arrivare alla foglia
    while (parent->left != NULL)
        parent = parent->left;
    
    return parent;
}


/**
 * Metodo che cerca il succesore 
 * inorder di un dato nodo
 * 
 * @param node nodo di cui si deve 
 *              trovare il Successore
 * @return temp che è il Successore
 * 
*/
TreeNode successor(TreeNode node){

    // Variabile per salvare l'ultimo nodo da cui 
    // si è girato a sinistra
    TreeNode tempLeft = NULL;
    TreeNode temp = NULL;

    // Se il nodo ha una subtree a destra
    if(node->right != NULL){
        temp  = node->right;
        return findMin(temp);
    }else{
      // Se il nodo non ha una subtree a destra

      temp = node;
      

      // Finchè non trova il nodo corispondete
      while (node->data != node->data){
          
          // Se nodo da cercare è minore
          // continua ricerca a sinistra e salva nodo
          if(node->data < node->data){
              tempLeft= node;
              node = node->left;

          // Continua ricerca a destra    
          }else{
              node = node->right;
          }
        return temp;  
      }
    }

    return tempLeft;
        
}


/**
 * Metodo che cerca il succesore 
 * inorder di un dato nodo
 * 
 * @param node nodo di cui si deve 
 *              trovare il Predeccesore
 * @return temp che è il Predeccesore
 */
TreeNode findPredecessor(TreeNode node) {

    TreeNode tempRight = NULL;
    if(node->left != NULL){
      TreeNode temp =node->left;
      while (temp->right != NULL){
        temp =temp->right;
      }
      return temp;
    }else {
      TreeNode temp = root;
      while (node->data != temp->data){
        if(node->data > temp->data){
          tempRight= temp;
          temp = temp->right;
        }else
          temp =temp->left;
      }
      return tempRight;
    }
}


/**
 * 
 * Metodo che aggiunge un elemento in ordine:
 * Tutti gli elementi più PICCOLI sono a SINSTRA del NODO PARENT
 * Tutti gli elementi più GRANDI sono a DESTRA del NODO PARENT
 * 
 * @param parent uso ricorsivo
 * @param key valore da inserire
 * @return NUlL = inserimento riuscito  
*/
int add(TreeNode parent, int key){
    
    // CASO#1:_ Albero Vuoto
    if(root == NULL){
        // Root divene il nuovo elemento
        root = create(key);
        return -1;
    }


    /**
     * (Condizioni di uscita dalla ricorsione)
     * CASO#2:_ ROOT E NELLE FOGLIE
     * 
     * Controllo se sono arrivato alle foglie di sinistra
     * grazie a NULL, e se la Key è minore di parent
     * 
     * if(true)
     * --- Aggiungo elemento alla sinistra del nodo corrente
     * 
     * if(False)
     * --- Controllo se sono arrivato alle foglie di sinistra
     * --- if(true)
     * ------- Aggiungo elemento alla destra del nodo corrente
    */  
    if (parent->left == NULL && key < parent->data){
        parent->left = create(key);
        return 0;


    }else if (parent->right == NULL && key > parent->data){
        parent->right = create(key);
        return 0;
    }else if(parent->data == key){
        printf("Duplicate element!\n");
        return 0;
    }
    

     /*
     * Se la key è minore del nodo corrente richiamo 
     * l'inserimento passandogli la subtree di sinistra
     */
    if (key < parent->data)
        add(parent->left, key);

     /*
     *  richiamo l'inserimento passandogli la subtree di destra
     */    
    else
        add(parent->right, key);

 
    return 0;
}


/**
 * Metodo cancella un elemento nel albero,
 * in base alla key. Uso della ricorsione 
 * per associazione a risalire dei figli 
 * del parent.
 * 
 * @param parent uso ricorsivo 
 * @param key valore da ricercare e eleminare 
 * @return temp to unite the child to parent
*/
TreeNode deleteNode(TreeNode  parent, int key) {
    // base case 
    if (parent == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (key < parent -> data) {
      parent -> left = deleteNode(parent -> left, key);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > parent -> data) {
     parent -> right = deleteNode(parent -> right, key);
    }

    // If key is same as root's key, then This is the node to be deleted 
    else {
      // Node with ONLY ONE child or NO CHILD
      if (parent -> left == NULL) {
        TreeNode temp = parent -> right;
        free(parent);
        return temp;
      } else if (parent -> right == NULL) {
        TreeNode  temp = parent -> left;
        free(parent);
        return temp;
      } else {

        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode  temp = findMin(parent -> right);
        // Copy the inorder successor's content to this node 
        parent -> data = temp -> data;
        // Delete the inorder successor 
        parent -> right = deleteNode(parent -> right, temp -> data); 
      }
    }
    return parent;
  }


// Free the full tree using recursion  
void deleteTree(TreeNode node) {
    /*  Base case */
    if (node == NULL) 
      return;
  
    /* First delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
    
    /* Then delete the node */
    printf("\n Deleting node: %d", node->data);
    free(node);
    root = NULL;

}


/**
 * Metodo che cerca la key nel albero 
 * utilizzando la ricorsione e comparazione 
 * si sposta nel sottoalbero che conviene
 * finche non trova la key o non la trova
 * 
 * @param parent uso ricorsivo
 * @param key dato da ricercare nella Tree
 */
TreeNode search(TreeNode parent, int key) {

    // Caso root vuota o root elemento che combacia
    if (parent == NULL || parent -> data == key)
      return parent;

    /** 
     * Se no controllo che la key sia minore del 
     * parrent corrente e continuo la 
     * ricorsione a sinistra
     */ 
    else if (key < parent -> data)
      return search(parent -> left, key);

    // La key è maggiore dell parent corrente
    // continuo la ricorsione a destra
    else
      return search(parent -> right, key);
  }








/**
 *              @author Yash Kumar 
 *                                @since 2002
 */