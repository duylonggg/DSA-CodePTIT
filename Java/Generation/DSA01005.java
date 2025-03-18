import java.util.Arrays;
import java.util.Scanner;

public class DSA01005 {
    static void nextPermutation(int[] A, int N) {
        for (int num : A) {
            System.out.print(num);
        }
        System.out.print(" ");

        int pos = N - 2;
        while (pos >= 0 && A[pos] > A[pos + 1]) --pos;

        if (pos == -1) {
            Arrays.sort(A);
            return;
        }

        int swap_pos = N - 1;
        while (A[swap_pos] < A[pos]) --swap_pos;

        int temp = A[pos];
        A[pos] = A[swap_pos];
        A[swap_pos] = temp;
        Arrays.sort(A, pos + 1, N);

        nextPermutation(A, N);
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt();

            int[] A = new int[N];
            for (int i = 0; i < N; ++i) {
                A[i] = i + 1;
            }

            nextPermutation(A, N);

            System.out.println();
        }
        
        in.close();
    }
}
