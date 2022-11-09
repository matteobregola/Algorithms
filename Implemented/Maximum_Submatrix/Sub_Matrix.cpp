#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int KadaneAlgorithm(const vector <int> row_sum, int N){
    int maxHere=0;
    int maxSoFar=0;

    for(int i=0; i<N; i++){
        maxHere=max(maxHere+row_sum[i],0);
        maxSoFar=max(maxSoFar, maxHere);
    }

    return maxSoFar;
}


int main(){
    ifstream filein("input.txt");
    ofstream fileout("output.txt");

    int matrix[1000][1000];
    int ROWS,COLUMNS;
    filein >> ROWS >> COLUMNS;

    // Create the matrix with the data in the input file
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLUMNS; j++){
            int n;
            filein >> n;
            matrix[i][j] = n;
        }
    }

    
    int maxRectangleSum=0;

    
    
    for(int i=0; i<COLUMNS; i++) {
        vector <int> row_sum(1000,0);
        for(int j=i; j<COLUMNS; j++){

            // da j=i to avoid swaps
            // i have to eval row_sum (from i to j)

            for (int m=0; m < ROWS; m++)
            {
                row_sum[m] += matrix[m][j];
                // row_sum[m]=sum_line(matrix,m,i,j);
            }

            // i have to apply the KadaneAlgorithm to row_sum
            int result;
            result=KadaneAlgorithm(row_sum,ROWS);
        
            if(result>maxRectangleSum){
                maxRectangleSum=result;
                
            }
              
        }
    }
    fileout << maxRectangleSum;
    
    return 0; 
}


/**
int sum_line(const int matrix[1000][1000],const int riga, const int i, const int j){
    int value=0;
    for(int m=i; m<=j;m++){
        value+= matrix[riga][m];
    }
    

    return value;
}
**/