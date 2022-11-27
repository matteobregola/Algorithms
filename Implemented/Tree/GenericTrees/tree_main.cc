using namespace std;
#include <iostream>
#include "tree.h"
    


int main() 
{
  
  tree t=init(4);
  write(t,5);
  tree m= parent(t);
  read(m); // GENERATE AN ERROR ON PURPOSE

  
  tree childT1=init(50); 
  insertchild(t,childT1);
  cout << t->child->item << endl;
  cout << childT1->parent->item << endl;

  tree sibiling_childT1=init(60);
  insertsibiling(childT1,sibiling_childT1);
  tree sibiling_childT2=init(600);
  insertsibiling(sibiling_childT1,sibiling_childT2);
  deletesibiling(childT1);
  read(sibiling_childT2);

  
  tree childT2=init(51); 
  insertchild(t,childT2);
  tree childT3=init(52); 
  insertchild(t,childT3);
  tree childT4=init(53); 
  insertchild(t,childT4);
  //deletetree(t);  

}