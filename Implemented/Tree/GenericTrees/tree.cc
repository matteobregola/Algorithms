using namespace std;
#include <iostream>
#include "tree.h"
#include <stdlib.h>
tree init(int v) {
  tree t= new node;
  t->item=v;
  t->parent=NULL;
  t->child=NULL;
  t->sibiling=NULL;
  return t;
}

void read(tree t){
  if(t==NULL){
    cout<<"ERROR: Trying to read in a null tree\n";
    return;
  }
  cout << t->item ;
}
void write(tree t, int v){
  if(t==NULL){
    cout<<"ERROR:Trying to write in a null tree\n";
    return;
  }
  t->item=v;
}

tree parent(tree t){
  if(t==NULL){
    cout<<"ERROR:Trying to find the parent of a null tree\n";
    return  NULL;
  }
  return t->parent;
}

tree leftmostchild(tree t){
  if(t==NULL){
    cout<<"ERROR:Trying to find the leftmostchild of a null tree\n";
    return NULL;
  }
  return t->child;
}

tree rightsibiling(tree t){
  if(t==NULL){
    cout<<"ERROR:Trying to find the rightsibiling of a null tree\n";
    return NULL;
  }
  return t->sibiling;
}

void insertchild(tree father, tree son){
  if(father==NULL ){
    cout<<"ERROR:Trying to insert child of a null tree\n";
    return ;
  }
  if(son==NULL ){
    cout<<"ERROR:Trying to insert a null tree as a child\n";
    return ;
  }
  son->parent=father;
  tree oldchild=father->child;
  father->child=son;
  son->sibiling=oldchild;
}

void insertsibiling(tree older, tree sibiling){
  if(older==NULL ){
    cout<<"ERROR:Trying to insert sibiling of a null tree\n";
    return;
  }
  if(sibiling==NULL ){
    cout<<"ERROR:Trying to insert a null tree as a sibiling\n";
    return;
  }
  sibiling->parent=older->parent;
  tree oldsibiling=older->sibiling;
  older->sibiling=sibiling;
  sibiling->sibiling=oldsibiling;
}
void deletesibiling(tree t){
  tree nextsibiling= t->sibiling->sibiling;
  delete(t->sibiling);
  t->sibiling=nextsibiling;
}

void deletechild(tree parent){
  if(parent==NULL ){
    cout<<"ERROR:Trying to delete child of a null tree\n";
    return;
  }
  if (parent->child==NULL){
    cout<<"ERROR:Trying to delete a null child of a tree\n";
    return;
  }
  
  tree oldsibiling=parent->child->sibiling;
  delete(parent->child);
  parent->child=oldsibiling;
  
  
}

void deletetree(tree t){
  tree oldchild=t->child;
  while(oldchild!=NULL){
    tree next=oldchild->sibiling;
    delete(oldchild);
    oldchild=next;
  }
  delete t;
}



void depthfirstsearch(tree t){
  if(t==NULL){
    return;
  }
  
  //here for pre order
  else{
    
    tree u=t->child;
    while (u!=NULL){
      depthfirstsearch(u);
      u=u->sibiling;
    }
    read(t);
    //here for postorder
  }
}


void breadthfirstsearch(tree t){
  
}