using namespace std;
#include <iostream>
#include "functions.hpp"

int main(){
    tree t=NULL;
    init(t);
    char value[2]={'m','y'};
    insert(t,value);
    print_indented(t);
}