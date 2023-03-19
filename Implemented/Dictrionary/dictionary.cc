using namespace std;
#include <iostream>
#include "functions.hpp"

int main(){
    tree t=NULL;
    init(t);
    char value[2]={'k','y'};
    insert(t,value);
    print_indented(t);
}