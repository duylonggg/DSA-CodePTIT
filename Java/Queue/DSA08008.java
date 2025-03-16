import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA08008 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            long N = in.nextInt();

            Queue<Long> queue = new ArrayDeque<>();
            queue.offer(1L);
            while (!queue.isEmpty()) {
                long num = queue.poll();

                if (num % N == 0) {
                    System.out.println(num);
                    break;
                }

                queue.offer(num * 10 + 0);
                queue.offer(num * 10 + 1);
            }
        }
        
        in.close();
    }
}
