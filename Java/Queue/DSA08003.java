import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class DSA08003 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Deque<Integer> deque = new ArrayDeque<>();
        int Q = in.nextInt();
        in.nextLine();
        while (Q-- > 0) {
            String query = in.nextLine();
            if (query.startsWith("PUSH")) {
                int num = Integer.parseInt(query.split(" ")[1]);
                if (query.contains("FRONT")) {
                    deque.offerFirst(num);
                } else {
                    deque.offerLast(num);
                }
            } else if (query.startsWith("PRINT")) {
                if (deque.isEmpty()) {
                    System.out.println("NONE");
                } else {
                    if (query.contains("FRONT")) {
                        System.out.println(deque.peekFirst());
                    } else {
                        System.out.println(deque.peekLast());
                    }
                }
            } else if (query.startsWith("POP")) {
                if (deque.isEmpty() == false) {
                    if (query.contains("FRONT")) {
                        deque.pollFirst();
                    } else {
                        deque.pollLast();
                    }
                }
            }
        }
        
        in.close();
    }
}