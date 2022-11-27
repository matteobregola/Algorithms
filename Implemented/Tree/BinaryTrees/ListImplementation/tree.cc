using namespace std;
#include <iostream>
#include "tree.h"

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

retval insert(tree & t, char v) {
  retval res;
  if (emptyp(t)) {
  // memo: "new (nothrow) ..." return NULL
  // if the allocation can't occur
    t = new (nothrow) node;
    if (t==NULL)
      res = FAIL; 
    else {
      t->item = v;
      t->left = NULL; 
      t->right = NULL; 
      res = OK;
    }
  }
  else if (v <= t->item) 
    res = insert(t->left, v);
  else if (v > t->item) 
    res = insert(t->right, v);
  return res;

  // insert a new node in the tree
  // if the tree is empty or a leave allocates a new node
  // if equal insert to the left

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


tree search_iterative(const tree & t, char elem){
  bool trovato=false;
  tree res;
  if (emptyp(t)){
    res = NULL;
  }
  else{
    res=t;
    while(res!=NULL && !trovato){
      if(elem==res->item){
        trovato=true;
      }
      else if (elem<res->item){
        res=res->left;
      }
      else{
        res=res->right;
      }
    }
    if(!trovato){
      res=NULL;
      // if element not present return NULL
    }
  }
  return res;
}

retval insert_iterative(tree & t, char v){
  retval res= OK;
  bool inserted=false;

  tree new_node = new (nothrow) node ;
  if(new_node==NULL){
    res = FAIL; // if i have no space in RAM
  }
  else{
    new_node->item=v;
    new_node->left=NULL;
    new_node->right=NULL;
  }

  if (emptyp(t)) {
    // memo: "new (nothrow) ..." return NULL
    // if the allocation can't occur
    t = new_node;
  }
  else{
    tree temp=t;
    while(temp!=NULL && !inserted )
    {
      if(new_node->item==temp->item){
        inserted=true;
        res= FAIL;
        // no duplicates, if wanted i can insert them left**
        // delete this and set <= in the 2 instructions below
        
      }
      else if(new_node->item < temp->item && temp->left == NULL){ //**
        temp->left=new_node ; // the node to insert is less of the temp one
        // and temp doesn't have a left child -> insert left
        inserted=true;
      }
      else if(new_node->item < temp->item){ //**
        temp=temp->left; //the node to insert is less of the temp one
        //but temp has a left child-> i go into this one
      }
      else if(new_node->item > temp->item && temp->right == NULL){
        temp->right=new_node ; // the node to insert is greater of the temp one
        //and temp doesn't have a right child -> insert tight
        inserted= true;
      }
      else{
        temp=temp->right;  // the node to insert is greater of the temp one
         //but temp has a right child-> i go into this one
      }
    }
  }
  return res;
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

static bool leaf(const tree &t){
  if(t->left==NULL && t->right==NULL){
    return true;
  }
  else{
    return false;
  }
  // verify if a node is a leaf
}

static bool father_of_one(tree &t){
  bool result=false;
  if(t->left==NULL && t->right!=NULL){
    result=true;
  }
  else if(t->left!=NULL && t->right==NULL){
    result=true;
  }
  return result;
}


tree find_child(const tree & t){
  tree current= t;
  // find the leftmost leaf
  while(current->left !=NULL){
    current=current->left;
  }
  return current;
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

tree delete_node(tree &r, int v){
  if(r==NULL){
    return NULL;
  }
  else if(v<r->item){
    r->left=delete_node(r->left,v);
  }
  else if(v>r->item){
    r->right=delete_node(r->right,v);
  }
  else{
    if(r->left==NULL){
      //1 o 0 child
      tree temp=r->right;
      delete r;
      return temp;
    }
    else if(r->right==NULL){
      tree temp=r->left;
      delete r;
      return temp;
    }
    else{
      tree temp=find_child(r->right);
      r->item=temp->item;
      r->right=delete_node(r->right,temp->item);
    }
  }
  // given a tree t, if i want to delete the node with the value 4 
  // then delete_node(t,4)
  return r;
}

// here should be char
void print_path(const tree & root, int element) {
  if (root == NULL) {
    cout << "Elemento not found!" << endl;
  }
  else if (root->item == element) {
    cout << "found!" << endl;
  }
  else if (root->item < element) {
    cout << root->item << ", right" << endl;
    print_path(root->right, element);
  }
  else {
    cout << root->item << ", lrft" << endl;
    print_path(root->left, element);
  }
  //print the path from the root to the node
}

void print_ordered(const tree & t) {
  if (!emptyp(t)) {
    print_ordered(t->left);
    cout << t->item << endl;
    print_ordered(t->right);
  }
  // print with order
}

void print_pre_ordered(const tree & t) {
  if (!emptyp(t)) {
    cout << t->item << endl;
    print_ordered(t->left);
    print_ordered(t->right);
  }
  // print with order
}

void print_post_ordered(const tree & t) {
  if (!emptyp(t)) {
    print_ordered(t->left);
    print_ordered(t->right);
    cout << t->item << endl;
  }
  // print with order
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



/**
tree find_parent(const tree &t, const tree &child){
  tree res;
  if (emptyp(t)) 
    res = NULL;
  else if(t->left==child || t->right==child)
    res = t;
  else if (child->item < t->item) 
    res = find_parent(t->left,child);
  else if (child->item > t->item)
    res = find_parent(t->right,child);
  return res;
}
not working
**/ 