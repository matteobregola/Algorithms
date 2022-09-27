#include <iostream>
#include <utility>

using namespace std;

void create_array(int *, int);
void print_array(int *,int);
void InsertionSort(int *, int);


int main(){
    // Test the algotihm

    int array[10];
    create_array(array, 10);

    InsertionSort(array, 10);
    

    print_array(array, 10);

}



void InsertionSort(int A[], int n){
    for(int i=1; i<n; i++){
        int tmp=A[i];
        int j=i;
        for(; j>0 && A[j-1]>tmp; j--){
            A[j]=A[j-1];
        }
        A[j]=tmp;
        print_array(A,n); //remove to see the steps
    }
}




// Other functions, only for testing
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

void create_array(int * arr, int dim){
    for(int i=0; i<dim; i++){
        cout << "Inserisci elemento: ";
        int n;
        cin >> n;
        arr[i] =n;
        cout << endl;
    }
}