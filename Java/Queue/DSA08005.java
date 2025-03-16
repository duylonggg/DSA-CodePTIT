import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA08005 {
    public static void Gen(int n) {
        Queue<String> queue = new ArrayDeque<>();
        queue.offer("1");

        while (n-- > 0) {
            String cur = queue.poll();
            
            System.out.print(cur + " ");

            queue.offer(cur + "0");
            queue.offer(cur + "1");
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int test = input.nextInt();
        while (test-- > 0) {
            int n = input.nextInt();
            Gen(n);
            System.out.println();
        }

        input.close();
    }
}
