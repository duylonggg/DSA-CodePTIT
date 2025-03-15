import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class DSA08001 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt(); 

        while (T-- > 0) {
            Deque<Integer> deque = new ArrayDeque<>();
            int n = input.nextInt(); 

            for (int i = 0; i < n; i++) {
                int query = input.nextInt();
                switch (query) {
                    case 1:
                        System.out.println(deque.size());
                        break;
                    
                    case 2:
                        System.out.println(deque.isEmpty() ? "YES" : "NO");
                        break;

                    case 3:
                        int x = input.nextInt();
                        deque.offerLast(x);
                        break;

                    case 4:
                        if (!deque.isEmpty()) {
                            deque.pollFirst();
                        }
                        break;

                    case 5:
                        System.out.println(deque.isEmpty() ? -1 : deque.peekFirst()); 
                        break;
                    
                    case 6:
                        System.out.println(deque.isEmpty() ? -1 : deque.peekLast()); 
                        break;
                }
            }
        }
        input.close();
    }
}
