public class Test {
    
    public static int binarySearch(int[] A, int i, int j, int element) {
        if (i > j) {
            return -1;
        } else {
            int mid = (i + j) / 2;
            if (element == A[mid]) {
                return mid;
            } else {
                if (element > A[mid]) {
                    return binarySearch(A, mid + 1, j, element);
                } else {
                    return binarySearch(A, i, mid - 1, element);
                }
            }
        }

        //complexity: 2log(n)
    }


    public static void main(String[] args){
        System.out.println(min(new int[]{1,2,3,-1,4},5));
        int []A=new int[]{8,9,20,30,41,56,60};
        System.out.println(binarySearch(A, 0, 6,56));

    }
}
