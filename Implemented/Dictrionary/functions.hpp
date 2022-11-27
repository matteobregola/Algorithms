#ifndef TREE_H 
#define TREE_H 
#include <iostream>
#include <tuple>

using namespace std;


char search(char key);
void insert(char key, char value);
void remove(char key);








// -------------- AUXILIARY TREE FUNCTIONS--------------
struct node;

typedef node * tree;

struct node 
{  
  tuple <char>item; // tree of chars
  tree parent;
  tree left;  
  tree right;
};

void init(tree &); //initialize the tree
void deinit(tree &); 

bool nullp(const tree & ); //check if the tree is empty
bool insert(tree &, char); //insert an element into the tree
tree search (const tree &,char); //search in the tree

void depth_first_search(const tree & , int);
void print_indented(const tree &); // stamp with a tree structure
int count(const tree &);
tree find_parent(const tree &); 






// AUXILIARY FUNCTIONS 

static void print_spaces(int depth) {
  for(int i=0;i<depth;i++) 
    cout << "  ";
}
static bool emptyp(const tree & t) {
  return (t==NULL);
}

// MAIN FUNCTIONS

void init(tree & t) {
  t=NULL;
  //init the tree, create the root
}
void deinit(tree & t) {
  if (!emptyp(t)) {
    deinit(t->left);
    deinit(t->right);
    delete t;
  }
  // if the node is not empty delete left and then right
}
bool nullp(const tree & t) {
  return (t==NULL);
  // checks if the node is empty
}


bool insert_aux(tree & father, tree & t, char v) {
  bool res;
  if (emptyp(t)) {
  // memo: "new (nothrow) ..." return NULL
  // if the allocation can't occur
    t = new (nothrow) node;
    if (t==NULL)
      res = false; 
    else {
      t->item = v;
      t->left = NULL; 
      t->right = NULL; 
      t->parent = father;
      res = true;
    }
  }
  else if (v <= t->item) 
    res = insert_aux(t,t->left, v);
  else if (v > t->item) 
    res = insert_aux(t,t->right, v);
  return res;

  // insert a new node in the tree
  // if the tree is empty or a leave allocates a new node
  // if equal insert to the left

}
bool insert(tree & t, char v){
  if(t==NULL){
    tree m=NULL;
    return insert_aux(m,t,v);
  }
  else
    return insert_aux(t->parent, t, v);
}

tree  search (const tree & t,char elem) { 
  tree res;
  if (emptyp(t)) 
    res = NULL;
  else if (elem==t->item)
    res = t;
  else if (elem < t->item) 
    res = search(t->left,elem);
  else if (elem > t->item)
    res = search(t->right,elem);
  return res;
  
}

void depth_first_search(const tree & t, int mode=0){
  if(!nullp(t)){
    if(mode==0){
      // do here the pre order actions
      cout << t->item << " ";
      depth_first_search(t->left,mode);
      depth_first_search(t->right,mode);
    }
    else{
      if(mode==1){
        depth_first_search(t->left,mode);
        //do here the in order actions
        cout << t->item << " ";
        depth_first_search(t->right,mode);
      }
      else{
        if(mode==2){
          depth_first_search(t->left,mode);
          depth_first_search(t->right,mode);
          //do here the post order actions
          cout << t->item << " ";
        }
        else{
          cout << "mode not valid" << endl;
        }
      }
    }
  }
}

int count(const tree & t){
  if(nullp(t)){
    return 0;
  }
  else{
    int cl=count(t->left);
    int cr=count(t->right);
    return cl+cr+1;
  }
}

tree find_parent(const tree & t){
  return t->parent;
}



void print_indented(const tree & t) { 
  static int depth=0;
  depth++;
  if (!emptyp(t)) {
    print_indented(t->right);
    print_spaces(depth);
    cout << t->item << endl;
    print_indented(t->left);
  }
  depth--;
  // print with depth
}

#endif