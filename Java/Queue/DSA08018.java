import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA08018 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt();

            Queue<String> queue = new ArrayDeque<>();
            Queue<String> res = new ArrayDeque<>();
            queue.offer("6");
            queue.offer("8");
            while (!queue.isEmpty()) {
                String cur = queue.poll();

                if (cur.length() > N) {
                    break;
                }

                res.offer(cur);
                queue.offer(cur + "6");
                queue.offer(cur + "8");
            }

            System.out.println(res.size());
            while (!res.isEmpty()) {
                System.out.print(res.poll() + " ");
            }
            System.out.println();
        }
        
        in.close();
    }
}
