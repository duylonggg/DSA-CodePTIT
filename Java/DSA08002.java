import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA08002 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Queue<Integer> queue = new ArrayDeque<>();
        
        int Q = input.nextInt();
        input.nextLine();

        while (Q-- > 0) {
            String query = input.nextLine();
            
            if (query.startsWith("PUSH")) {
                int x = Integer.parseInt(query.split(" ")[1]);
                queue.offer(x);
            } else if (query.equals("POP")) {
                if (!queue.isEmpty()) {
                    queue.poll();
                }
            } else if (query.equals("PRINTFRONT")) {
                if (!queue.isEmpty()) {
                    System.out.println(queue.peek());
                } else {
                    System.out.println("NONE");
                }
            }
        }
        input.close();
    }
}
