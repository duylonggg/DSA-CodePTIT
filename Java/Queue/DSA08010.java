import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;

public class DSA08010 {
    public static int BFS(int N) {
        HashSet<Integer> vis = new HashSet<>();
        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        vis.add(N);
        priorityQueue.offer(new int[]{0, N});

        while (!priorityQueue.isEmpty()) {
            int[] cur = priorityQueue.poll();
            int steps = cur[0], num = cur[1];

            if (num == 1) {
                return steps;
            }

            if (vis.contains(num - 1) == false) {
                if (num - 1 == 1) {
                    return steps + 1;
                }
                vis.add(num - 1);
                priorityQueue.offer(new int[]{steps + 1, num - 1});
            }
            for (int i = (int) Math.sqrt(num); i >= 2; --i) {
                if (num % i == 0) {
                    if (vis.contains(num / i) == false) {
                        if (num / i == 1) {
                            return steps + 1;
                        }
                        vis.add(num / i);
                        priorityQueue.offer(new int[]{steps + 1, num / i});
                    }
                }
            }
        }
        return 0;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt();
            System.out.println(BFS(N));
        }
        
        in.close();
    }
}
