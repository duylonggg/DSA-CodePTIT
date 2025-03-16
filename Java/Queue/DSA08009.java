import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA08009 {
    public static int changeSToT(int S, int T) {
        int[] vis = new int[10001];
        Queue<int[]> queue = new ArrayDeque<>();
        vis[S] = 1;
        queue.offer(new int[]{S, 0});

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int num = cur[0], steps = cur[1];

            if (num == T) {
                return steps;
            }

            if (num * 2 < 10000 && vis[num * 2] == 0) {
                vis[num * 2] = 1;
                queue.offer(new int[]{num * 2, steps + 1});
            }
            if (num - 1 > 0 && vis[num - 1] == 0) {
                vis[num - 1] = 1;
                queue.offer(new int[]{num - 1, steps + 1});
            }
        }
        return 0;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int S = in.nextInt(), T = in.nextInt();

            System.out.println(changeSToT(S, T));
        }
        
        in.close();
    }
}
