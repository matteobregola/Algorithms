using namespace std;
#include <iostream>
#include "tree.h"

/**
 * Test Program for the tree implementation
 * Remeber to compile with tree.cc (es g++ tree_main.cc tree.cc)
 * @author matte
 */

int main() 
{
  char option,val;
  tree t, tmp;
  retval res;
  init(t);
  do {
    cout << "\nPossible Operations:\n"
         << "Insertion (i)\n" 
         << "Search(r)\n" 
         << "Print with order (s)\n" 
         << "Print indented (e)\n"
         << "Fine (f)\n";
    cin >> option;
    switch (option) {
    case 'i':
      cout << "Val? : ";
      cin >> val;
      res = insert(t,val);
      if (res == FAIL)
        cout << "No space, the tree is full!\n";
      break;
    case 'r':
      cout << "Val? : ";
      cin >> val;
      tmp=search(t,val);
      if (!nullp(tmp))
        cout << "Value Found!: " << val << endl;
      else
        cout << "Value non Found!\n";
      break;
    case 's':
      cout << "Print with Order:\n";
      print_ordered(t);
      break;
    case 'e':
      cout << "Print indented:\n";
      print_indented(t);
      break;
    case 'f':
      break;
    default:
      cout << "Wrong option\n";
    }
  } while (option != 'f');
  deinit(t);
}
