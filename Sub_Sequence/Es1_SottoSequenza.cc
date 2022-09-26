#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream filein("input.txt");
    ofstream fileout("output.txt");

    int sequence[100000];

    int N;
    filein >> N;

    for(int i = 0; i < N; i++){
        filein >> sequence[i];
    }
    int maxSoFar=0;
    int maxHere=0;

    for(int i=0; i<N; i++){
        maxHere=max(maxHere+sequence[i],0);
        maxSoFar=max(maxSoFar, maxHere);
    }


    fileout << maxSoFar;
    
    return 0;
}