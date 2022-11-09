using namespace std;
#include <iostream>
#include "tree.h"

// AUXILIARY FUNCTIONS (not visible to main)

static tree left(const tree & t) {
  tree res;
  res.pos = 2*t.pos+1;
  res.array=t.array;
  return res;

  // given a tree returns the left node (tree)
  
}

static tree right(const tree & t) {
  tree res;
  res.pos = 2*t.pos +2;
  res.array=t.array;
  return res;

  // given a tree returns the left node (tree)
}

static char & elem(const tree & t) {
  return t.array[t.pos];

  // given an array return the elemnt in the i-th position
}

static int emptyp(const tree & t) {
  return (elem(t)=='\0');
}

bool nullp(const tree & t) {
  return (t.pos==-1);
}

static tree mknull() {
  tree res;
  res.pos=-1;
  return res;

  // creates an empty tree
}

static void print_spaces(int depth) {
  for(int i=0;i<depth;i++) 
      cout << "  ";
}



// MAIN FUNCTIONS

void init(tree & t) {
  t.pos=0;
  t.array = new char[MAXSIZE];
  for (int i=0;i<MAXSIZE;i++)
    t.array[i] = '\0';

  // init the tree, allocates the array and all the elements to '\0'
  
}

void deinit(tree & t) {
  delete [] t.array;
}


retval insert(tree & t, char v) {
  tree t1;
  retval res;
  if (t.pos >= MAXSIZE)
    res = FAIL;
  else if (emptyp(t)) {
    elem(t)=v; 
    res = OK;
  }
  else if (v <= elem(t)) {
    t1 = left(t);
    res = insert(t1,v);
  }
  else {
    t1 = right(t);
    res = insert(t1,v);
  }
  return res;

  // given a tree t, checks if is full or empty, in the first case ir teturns FAIL
  // if not it inserts the v element
  
}

tree search (const tree & t,char item) { 
  tree res;
  if (emptyp(t)) {
    res = mknull();
  }
  else if (elem(t)==item) {
    res = t;
  }
  else if (elem(t)>item) {
    res = search(left(t),item);
  }
  else {
    res = search(right(t),item);
  }
  return res;
  
  // seatch an element, if the tree is empty returns an emtpy tree
}


void print_ordered(const tree & t) {
  if (!emptyp(t)) {
    print_ordered(left(t));
    cout << elem(t) << endl;
    print_ordered(right(t));
  }
}

void print_indented(const tree & t) {
  static int depth=0;
  depth++;
  if (!emptyp(t)) {
    print_indented(right(t));
    print_spaces(depth);
    cout << elem(t) << endl;
    print_indented(left(t));
  }
  depth--;
}