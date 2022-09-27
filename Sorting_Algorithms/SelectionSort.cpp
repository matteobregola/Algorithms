#include <iostream>
#include <utility>

using namespace std;

void create_array(int *, int);
void print_array(int *,int);
void SelectionSort(int *, int);
void SelectionSort2(int *, int);
pair <int,int> min(const int *, const int, const int);

int main(){
    // Test the algotihm

    int array[10];
    create_array(array, 10);

    SelectionSort(array, 10);
    // SelectionSort2(array, 10);

    print_array(array, 10);

}

pair <int,int> min(const int A[],const int index, const int n){
    // i evalute both the minimun and it's index
    // i need the index because i have to replace the value in the current
    // index (passed to the function) there 
    int min=A[index];
    int min_index=index;
    for(int m=index; m<n; m++){
        if(A[m]<min){
            min=A[m];
            min_index=m;
        }
    }

    pair <int,int> value(min,min_index);
    return value;
}

void SelectionSort(int A[], int n){
    for(int i=0; i<n; i++){
        int tmp=A[i];
        pair<int, int> swap= min(A,i,n);
        A[i]=swap.first;
        A[swap.second]=tmp;

        //print_array(A,n); remove to see the steps
    }
}


// One function version:
void SelectionSort2(int A[], int n){
    int i, j, min, temp;

    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if (A[j]<A[min]){
                min= j;
            }
        }
        temp=A[min];
        A[min]=A[i];
        A[i]=temp;
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