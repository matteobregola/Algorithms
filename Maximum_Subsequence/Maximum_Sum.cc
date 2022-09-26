#include <iostream>
using namespace std;

int main(){
    int sequence[100000];

    int N;
    cout << "Insert the number of integers: " ;
    cin >> N;
    

    for(int i = 0; i < N; i++){
        cout << "Insert element " << i <<  ": ";
        cin >> sequence[i];
        cout << endl;
    }
    int maxSoFar=0;
    int maxHere=0;

    for(int i=0; i<N; i++){
        maxHere=max(maxHere+sequence[i],0);
        maxSoFar=max(maxSoFar, maxHere);
    }


    cout << "The Maximum Subsequence Sum is: " << maxSoFar << endl << endl;
    
    return 0;
}