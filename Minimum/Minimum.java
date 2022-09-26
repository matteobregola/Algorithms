public static int min(int []S, int n){
        int min=S[0];
        for(int i=1; i<n; i++){
            if(S[i]<min){
                min=S[i];
            }
        }

        return min;

        //complexity n-1
    }
