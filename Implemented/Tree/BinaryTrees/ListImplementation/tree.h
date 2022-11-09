#ifndef TREE_H 
#define TREE_H 

enum retval {FAIL,OK};

struct node;

typedef node * tree;

struct node 
{  
  char item; // tree of chars
  tree left;  
  tree right;
};

void init(tree &); //initialize the tree
void deinit(tree &); 
bool nullp(const tree & ); //check if the tree is empty
retval insert(tree &, char); //insert an element into the tree
tree search (const tree &,char); //search in the tree
void print_ordered(const tree &); //ordered print
void print_indented(const tree &); // stamp with a tree structure

tree delete_node(tree &t, int); //(should be a char)
tree search_iterative(const tree & , char ); //R
retval insert_iterative(tree & , char);
//bool leaf(const tree&);
tree find_parent(const tree & , const tree & ); 
void print_path(const tree & root, int element);


//es 3: funzioni: void ordinaArray(int array[], int dim) albero creaAlberoBilanciato(int array[], int dim) 
// void inserisciNodoBilanciato(albero& radice, int array[], int indiceBasso, int indiceAlto) 

#endif
