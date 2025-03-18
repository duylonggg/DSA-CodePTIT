import java.util.Arrays;
import java.util.Scanner;

public class DSA01027 {
    static void nextPermutation(int[] A, int N) {
        for (int num : A) {
            System.out.print(num + " ");
        }
        System.out.println();

        int pos = N - 2;
        while (pos >= 0 && A[pos] > A[pos + 1]) --pos;

        if (pos == -1) {
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

        int N = in.nextInt();

        int[] A = new int[N];
        for (int i = 0; i < N; ++i) {
            A[i] = in.nextInt();
        }

        Arrays.sort(A, 0, N);
        nextPermutation(A, N);
        
        in.close();
    }
}
