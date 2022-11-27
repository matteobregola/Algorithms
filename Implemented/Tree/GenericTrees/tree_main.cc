using namespace std;
#include <iostream>
#include "tree.h"
    


int main() 
{
  
  tree a= init(1);
  tree b= init(2);
  tree c= init(3);
  tree d= init(4);
  tree e= init(5);
  tree f= init(6);
  tree g= init(7);
  tree h= init(8);
  tree i= init(9);
  insertchild(a,b);
  insertsibiling(b,i);
  insertsibiling(b,e);
  insertchild(b,c);
  insertsibiling(c,d);
  insertchild(e,f);
  insertsibiling(f,h);
  insertsibiling(f,g);
  breadthfirstsearch(a);
  deletetree(a);  

}