#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

void create_array(int *, int);
void print_array(int *,int);
void MergeSort(int [],int, int);

int main(){
    // Test the algotihm

    int array[10];
    create_array(array, 10);

    MergeSort(array, 0, 9); 

    print_array(array, 10);

}

void Merge(int A[], int first, int last, int med){
    int i=first;
    int j=med +1;
    int k=first;
    
    int * B = new int[last +1];
    while(i<=med && j<= last){
    
        if(A[i]<=A[j]){
            
            B[k]=A[i];
            i++;
        }
        else{
            B[k]=A[j];
            j++;
        }
        
        k++;
    }

    j=last;

    for(int h=med; h>=i; h--){
        A[j]=A[h];
        j--;
    }

    for(int g=first; g<=k-1; g++){
        A[g]=B[g];
    }

    delete [] B; 
}

void MergeSort(int A[], int first, int last){
    if (first<last){
        int med= ceil((first+last)/2);
        MergeSort(A,first,med);
        MergeSort(A,med+1,last);
        Merge(A,first,last,med);
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
        cout << "Insert  element: ";
        int n;
        cin >> n;
        arr[i] =n;
        cout << endl;
    }
}