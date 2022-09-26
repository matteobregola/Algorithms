import static java.lang.Math.max;

public class Maximum_Sum{

    public static int sum(int[] A, int i, int j){
        int sum = 0;
        for(int m = i; m < j; m++){
            sum += A[m];
        }
        return sum;
    }

  
    int maxsum1(int[] A, int n) {
        int maxSoFar = 0;
        for (int i=0; i < n; i++) {
            for (int j=i; j < n; j++) {
                maxSoFar = max(maxSoFar, sum(A, i, j));
            }
        } return maxSoFar;
    }

    int maxsum2(int[] A, int n) {
        int maxSoFar = 0;
        for (int i=0; i < n; i++) {
            int sum = 0;
            for (int j=i; j < n; j++) {
                sum = sum + A[j];
                maxSoFar = max(maxSoFar, sum);
            }
        } return maxSoFar;
    }

    int maxsum3(int[] A, int n) {
        int m=A.length/2;;
        int maxLL=0;
        int sum=0;

    }

    int maxsum4(int A[], int n) {
        int maxSoFar = 0;
        int maxHere = 0;
        for (int i=0; i < n; i++) {
            maxHere = max(maxHere+A[i], 0);
            maxSoFar = max(maxSoFar,maxHere);
         }
        return maxSoFar;
    }


}
