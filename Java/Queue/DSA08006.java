import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA08006 {
    public static int findMinDiv(int n) {
        Queue<Integer> queue = new ArrayDeque<>();

        queue.offer(9);
        while (queue.peek() % n != 0) {
            int num = queue.poll();

            queue.offer(num * 10 + 0);
            queue.offer(num * 10 + 9);
        }

        return queue.peek();
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int test = in.nextInt();
        while (test-- > 0) {
            int n = in.nextInt();
            System.out.println(findMinDiv(n));
        }
        
        in.close();
    }
}
