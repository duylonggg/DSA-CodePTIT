import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA01015 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int test = in.nextInt();
        while (test-- > 0) {
            int N = in.nextInt();

            Queue<Long> queue = new ArrayDeque<>();
            queue.offer(9L);
            while (queue.peek() % N != 0) {
                long num = queue.poll();

                queue.offer(num * 10 + 0);
                queue.offer(num * 10 + 9);
            }

            System.out.println(queue.peek());
        }
        
        in.close();
    }
}
