using namespace std;
#include <iostream>
#include "tree.h"


int main() 
{
  char option,val;
  int val2, val3;
  tree t, tmp;
  tree new_node;
  retval res;
  char arr[6]={'a', 'b', 'c', 'd', 'e','f'};
  init(t);
  do {
    cout << "\nPossible Operations:\n"
         << "Insertion (i)\n" 
         << "Search(r)\n" 
         << "Count nodes(c)\n"
         << "Print with order (s)\n" 
         //<< "Parent finder (p)\n"
         << "Minimum distance (m)\n"
         << "Node level (a)\n"
         << "Node level recursive (x)\n"
         << "Print indented (e)\n"
         <<"Depth first search (q)\n" 
         << "Delete element (d)\n"
         << "Exit (f)\n";
    cin >> option;
    switch (option) {
    case 'i':
      cout << "Val? : ";
      cin >> val;
      res = insert(t,val);
      if (res == FAIL)
        cout << "No space, your ram is full!\n";
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
    
    case 'c':
      cout<< count(t);
      
      break;
    case 'q':
      cout << "Mode? : ";
      cin >> val2;
      depth_first_search(t,val2);
      break;

      /**
       Not working:
      case 'p':
        cout << "Parent of who? " << endl;
        cin>> val;
        cout << "The father is: "<<  find_parent(t,search(t,val))->item << endl;
        break;
      **/
    case 'm':
      cout << "The minimum distance is: " <<minimum_distance(t) << endl;
      break;
    case 'd':
      cout << "Insert the value of the element to delete: " ;
      cin >>val;
      new_node=search(t,val);
      if(new_node!=NULL){
        delete_node(t,val);
        cout << endl << "Value removed" << endl;
      }
      else{
        cout << "Value not found"<< endl;
      }
      break;
    case 's':
      cout << "Print ordered:\n";
      print_ordered(t);
    case 'a':
      cout << "Insert the level: " ;
      cin >>val2;
      val3=node_level(t,val2);
      cout << "nodes: " << val3 << endl;
      break;

    case 'x':
      cout << "Insert the level: " ;
      cin >>val2;
      val3=depth(t,val2);
      cout << "nodes: " << val3 << endl;
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