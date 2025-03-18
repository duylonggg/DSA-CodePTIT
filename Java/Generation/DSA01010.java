import java.util.HashMap;
import java.util.Scanner;

public class DSA01010 {
    static int count = 0;
    static HashMap<Integer, Integer> map = new HashMap<>();
    
    public static int Gen(int N, int K, int[] A) {
        int pos = -1;
        for (int i = K - 1; i >= 0; --i) {
            if (A[i] != N - K + i + 1) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            return K;
        }

        ++A[pos];
        count += (!map.containsKey(A[pos]) ? 1 : 0);
        for (int i = pos + 1; i < K; ++i) {
            A[i] = A[i - 1] + 1;
            count += (!map.containsKey(A[i]) ? 1 : 0);
        }
        return count;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            count = 0;
            map.clear();

            int N = in.nextInt(), K = in.nextInt();
            int[] A = new int[K];
            for (int i = 0; i < K; ++i) {
                A[i] = in.nextInt();
                map.put(A[i], 1);
            }

            System.out.println(Gen(N, K, A));
        }   
        
        in.close();
    }
}
