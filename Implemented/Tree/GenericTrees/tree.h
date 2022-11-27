#ifndef TREE_H 
#define TREE_H 

struct node;

typedef node * tree;

struct node 
{  
  int item; // tree of int
  tree parent;  
  tree sibiling;
  tree child;
};

void init(tree &); //initialize the tree
void deinit(tree &); 
bool nullp(const tree & ); //check if the tree is empty
bool insert(tree &, int); //insert an element into the tree
tree search (const tree &,int); //search in the tree
void depth_first_search(const tree & , int);
void print_ordered(const tree &); //ordered print
void print_indented(const tree &); // stamp with a tree structure
int count(const tree &);
tree delete_node(tree &t, int); 
tree search_iterative(const tree & , int ); //R
retval insert_iterative(tree & , int);
//bool leaf(const tree&);
tree find_parent(const tree & , const tree & ); 
void print_path(const tree & root, int element);


//es 3: funzioni: void ordinaArray(int array[], int dim) albero creaAlberoBilanciato(int array[], int dim) 
// void inserisciNodoBilanciato(albero& radice, int array[], int indiceBasso, int indiceAlto) 

#endif
