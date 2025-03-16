import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA08007 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();

        while (testCases-- > 0) {
            long N = in.nextLong();
            int ans = 0;

            Queue<Long> queue = new ArrayDeque<>();
            queue.offer(1L);

            while (!queue.isEmpty()) {
                long num = queue.poll();

                if (num > N) break;

                num *= 10;
                if (num == N || num + 1 == N) {
                    ++ans;
                    break;
                }

                ++ans;
                queue.offer(num);
                queue.offer(num + 1);
            }

            System.out.println(ans);
        }

        in.close();
    }
}
