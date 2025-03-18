import java.util.*;

public class DSA01023 {
    public static int GenCombination(int[] originConfig, int[] finalConfig, int N, int K) {
        int times = 1;

        while (!Arrays.equals(originConfig, finalConfig)) {
            int pos = K - 1;
            while (pos >= 0 && originConfig[pos] == N - K + pos + 1) {
                --pos;
            }

            if (pos >= 0) {
                originConfig[pos]++;
                for (int i = pos + 1; i < K; ++i) {
                    originConfig[i] = originConfig[i - 1] + 1;
                }
            }

            times++;
        }
        
        return times;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt(), K = in.nextInt();

            int[] originConfig = new int[K];
            int[] finalConfig = new int[K];
            for (int i = 0; i < K; ++i) {
                originConfig[i] = i + 1;
                finalConfig[i] = in.nextInt();
            }

            System.out.println(GenCombination(originConfig, finalConfig, N, K));
        } 
        
        in.close();
    }
}
