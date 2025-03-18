import java.util.Scanner;

public class DSA01004 {
    public static void nextCombination(int[] A, int N, int K) {
        for (int num : A) {
            System.out.print(num);
        }
        System.out.print(" ");

        int pos = -1;
        for (int i = K - 1; i >= 0; --i) {
            if (A[i] != N - K + i + 1) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            for (int i = 0; i < K; ++i) {
                A[i] = i + 1;
            }
            return;
        }

        ++A[pos];
        for (int i = pos + 1; i < K; ++i) {
            A[i] = A[i - 1] + 1;
        }
        nextCombination(A, N, K);
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt(), K = in.nextInt();

            int[] A = new int[K];
            for (int i = 0; i < K; ++i) {
                A[i] = i + 1;
            }

            nextCombination(A, N, K);

            System.out.println();
        }
        
        in.close();
    }
}
