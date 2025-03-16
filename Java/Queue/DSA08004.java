import java.util.PriorityQueue;
import java.util.Scanner;

public class DSA08004 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int K = in.nextInt();
            in.nextLine();
            String string = in.nextLine();

            int[] freq = new int[26];
            for (char c : string.toCharArray()) {
                ++freq[c - 'A'];
            }

            PriorityQueue<Integer> priorityQueue = new PriorityQueue<>((a, b) -> b - a);
            for (int i = 0; i < 26; ++i) {
                if (freq[i] != 0) {
                    priorityQueue.offer(freq[i]);
                }
            }

            while (K-- > 0 && !priorityQueue.isEmpty()) {
                int top = priorityQueue.poll();
                if (top > 1) {
                    priorityQueue.offer(top - 1);
                }
            }

            long ans = priorityQueue.stream().mapToLong(f -> (long) f * f).sum();

            System.out.println(ans);
        }
        
        in.close();
    }
}
