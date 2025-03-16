import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class DSA08017 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt();

            Queue<String> queue = new ArrayDeque<>();
            Stack<String> stack = new Stack<>();
            queue.offer("6");
            queue.offer("8");
            while (!queue.isEmpty()) {
                String cur = queue.poll();

                if (cur.length() > N) {
                    break;
                }

                stack.push(cur);
                queue.offer(cur + "6");
                queue.offer(cur + "8");
            }

            while (!stack.isEmpty()) {
                System.out.print(stack.pop() + " ");
            }
            System.out.println();
        }
        
        in.close();
    }
}
