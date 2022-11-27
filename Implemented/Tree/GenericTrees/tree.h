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

tree init(int);
void read(tree);
void write(tree, int);
tree parent(tree);
tree leftmostchild(tree);
tree rightsibiling(tree);
void insertchild(tree, tree); 
void insertsibiling(tree, tree);
void deletechild(tree); 
void deletesibiling(tree);
void deletetree(tree);
void depthfirstsearch(tree);
void breadthfirstsearch(tree);

#endif