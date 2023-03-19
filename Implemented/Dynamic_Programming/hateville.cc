#include <iostream>
using namespace std;

int n=0;

int hateville(int * D, int n){
    int * DP= new int[n];
    
    DP[0]=0;
    DP[1]=D[1];
    
    for(int i=2; i<n;i++){
        DP[i]=max(DP[i-1],DP[i-2]+D[i]);
    }

    int result=DP[n-1];
    delete[] DP;

    return result;
}

void print_array(int *,int );



int main(){
    
    do
    {
        cout << "How many elements? " << endl; //-1 to terminate execution
        /* 
            NB: you have to asign also the value in the i=0 position
            logically should be 0 because with 0 element you woul have 0 profit
        */
        cin >> n;

        if (n<=0) exit(0);

        int * D = new int[n];

        for(int i=0; i<n; i++){
            int x;
            cout << "\nElement " << i << "= " ;
            cin >> x;
            D[i]=x;
        }

        cout << "\n \nGiven D:";
        print_array(D,n);

        cout << "The max profit is: " << hateville(D,n) <<endl << endl; 

        delete [] D;

    } while (n>=0);
    
    return 0;
}




void print_array(int a[],int dim){
    cout << '[' ;
    for (int i = 0; i < dim; i++){
        cout << a[i] ;
        if (i+1!=dim){
             cout << ',' ;
        }
    };
    cout << ']' << endl;
}
