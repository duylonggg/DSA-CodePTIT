import java.util.Scanner;

public class DSA01018 {
    static int n, k;
    static int[] v;

    static void print() {
        for (int i : v) System.out.print(i + " ");
        System.out.println();
    }

    static void gen() {
        int pos = -1;
        for (int i = k - 1; i >= 0; --i) {
            if (i > 0 && v[i] > v[i - 1] + 1) {
                pos = i;
                break;
            }
        }

        if (pos == -1 && v[0] == 1) {
            for (int i = 0; i < k; ++i)
                v[i] = n - k + i + 1;
            print();
            return;
        }

        pos = (pos == -1 ? 0 : pos);
        --v[pos];
        for (int i = pos + 1; i < k; ++i)
            v[i] = n - k + i + 1;
        print();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        
        while (testCases-- > 0) {
            n = scanner.nextInt();
            k = scanner.nextInt();
            v = new int[k];
            for (int i = 0; i < k; i++) v[i] = scanner.nextInt();
            gen();
        }
        
        scanner.close();
    }
}
