import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA08020 {
    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    public static int BFS(int S, int T) {
        int[] vis = new int[10000];
        vis[S] = 1;
        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{S, 0});

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int num = cur[0], steps = cur[1];

            if (num == T) return steps;

            String str = String.valueOf(num);
            for (int i = 0; i < 4; ++i) {
                for (char j = '0'; j <= '9'; ++j) {
                    if (str.charAt(i) == j) continue; 

                    StringBuilder tmp = new StringBuilder(str);
                    tmp.setCharAt(i, j);
                    int p = Integer.parseInt(tmp.toString());

                    if (p >= 1000 && vis[p] == 0 && isPrime(p)) {
                        if (p == T) return steps + 1;
                        vis[p] = 1;
                        queue.offer(new int[]{p, steps + 1});
                    }
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int Test = in.nextInt();

        while (Test-- > 0) {
            int S = in.nextInt(), T = in.nextInt();
            System.out.println(BFS(S, T));
        }
        in.close();
    }
}
