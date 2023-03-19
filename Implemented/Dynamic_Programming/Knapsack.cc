#include <iostream>
using namespace std;

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

int knapsack(int * w, int * p, int n, int C){
    
    /*
        w = weight of the element
        p = profitability of the element
        int n = number of element
        int C = capacity
    */
    int ** DP= new int *[n+1];
    for (int i = 0; i < n+1; i++) {
        DP[i] = new int[C+1];
    }

    
    for (int i = 0; i < n+1; i++){
        DP[i][0]=0;
        // profit with no capacity = 0
    }

    for (int c = 0; c < C+1; c++){
        DP[0][c]=0;

        // profit with no elements = 0 
    }

    /*
        the element in position DP[i][c] indicates the obtainable profit
        having considered the first i objects and a max capacity of C
        the maximum obtainable value will be DP[n][C]
        eg: capacity =9 but actually i need 10 elements from 0 to 9

        Note on the indexes the array of considered elements and capacity
        are actually n+1 and C+1 because i need the initialization done before
        but the weight and profit array are of the "right" dimension this mean
        that using the index for w and p we have to "shift" it by -1
    */

   

    for (int i = 1; i < n+1; i++){
        for (int c = 1; c < C+1; c++){
            if(w[i-1]<=c){
                DP[i][c]=max(DP[i-1][c-w[i-1]]+p[i-1],DP[i-1][c]);

                /*
                    max between:
                     - max profit obtainable having considered the previous objects
                       with the ability to fit even the "new" one
                     - max profit achievable with previous items and capacity
                       that is being considered
                */
            }
            else{
                DP[i][c]= DP[i-1][c];
            }
        } 
    }
    
    int maxValue=DP[n][C];
    // if i want also to evaluate the elements taken:
    int i=n;
    int c=C;
    while(i>=1){
        if(DP[i][c]==DP[i-1][c]){
            i--;
        }
        else{
            bool previous=false;
            int x=c;
            while(x>=1 && !previous){
                if(DP[i][c]==DP[i-1][x-w[i-1]]+p[i-1]){
                    #if defined(DEBUG) && defined(VERBOSE)
                    cout << "DP[i][c]=" <<DP[i][c]; 
                    cout<< " " << DP[i-1][x-w[i-1]]<< " + " << p[i-1] << endl;
                    cout << "  with previous: " << i-1 <<"  c= " << x<<endl;
                    #endif
                    previous=true;
                    cout << "Element w,p: (" << w[i-1] << "," <<p[i-1] <<")" <<endl;
                    c=x-w[i-1];
                    i--;
                }
                else{
                    cout << "here" <<endl;
                    x--;
                
                }
            }
        }
    }

    for (int i = 0; i < n+1; i++) {
        delete[] DP[i];
    }

    delete [] DP;

    return maxValue;;     
}


int main(){
    
    int C, p, w, n;

    #ifdef DEBUG
    C=7;
    n=4;
    int profit[]={10,7,8,6};
    int weight[] ={4,2,3,4};
    #endif

    #ifndef DEBUG
    cout << "How many elements: ";
    cin>> n;
    cout << endl << "Capacity= ";
    cin >> C;
    cout << endl;

    int * profit = new int[n];
    int * weight = new int[n];


    for (int i = 0; i < n; i++){
        cout << "\nElement " << i << " weight= ";
        cin >> w;
        weight[i]=w;
        cout << " profit = ";
        cin >> p;
        profit[i]=p;

    }

    #endif

    int maxProfit=knapsack(weight,profit,n,C);

    cout << maxProfit << endl;

    #ifndef DEBUG
    delete[] profit;
    delete[] weight;

    #endif

    return 0;
}

