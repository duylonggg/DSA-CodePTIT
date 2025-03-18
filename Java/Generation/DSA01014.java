import java.util.Scanner;

public class DSA01014 {
    static int n, k, s, cnt;

    public static void gen(int start, int total, int count) {
        if (total > s || count > k) return; 
        if (count == k && total == s) {
            ++cnt;
            return;
        }

        for (int i = start; i <= n; ++i) {
            gen(i + 1, total + i, count + 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            n = scanner.nextInt();
            k = scanner.nextInt();
            s = scanner.nextInt();
            if (n == 0 && k == 0 && s == 0) break; 

            cnt = 0;
            gen(1, 0, 0);
            System.out.println(cnt);
        }

        scanner.close();
    }
}
