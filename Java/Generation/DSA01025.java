import java.util.Scanner;

public class DSA01025 {
    public static void Combination(int N, int K, int[] combination) {
        for (int i = 0; i < K; ++i) {
            System.out.print((char) (combination[i] - 1 + 'A'));
        }
        System.out.println();

        int pos = K - 1;
        while (pos >= 0 && combination[pos] == N - K + pos + 1) {
            --pos;
        }

        if (pos == -1) {
            return;
        }

        ++combination[pos];
        for (int i = pos + 1; i < K; ++i) {
            combination[i] = combination[i - 1] + 1;
        }
        Combination(N, K, combination);
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt(), K = in.nextInt();

            int[] combination = new int[K];
            for (int i = 0; i < K; ++i) {
                combination[i] = i + 1;
            }
            Combination(N, K, combination);

            System.out.println();
        }
        
        in.close();
    }
}
