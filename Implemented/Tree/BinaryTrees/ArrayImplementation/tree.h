#ifndef TREE_H 
#define TREE_H 

enum retval {FAIL,OK};
// can use boolean instead of retval

const int MAXSIZE = 100;


struct tree {
  char * array;
  int pos;

  // tree of chars
};


void init(tree &);
void deinit(tree &);
bool nullp(const tree & );
retval insert(tree &, char);
tree search (const tree &,char);
void print_ordered(const tree &);
void print_indented(const tree &);

#endif
