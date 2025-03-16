import java.util.*;

public class DSA08021 {
    static int M, N;
    static int[][] A;

    static int BFS() {
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] vis = new boolean[1001][1001];

        queue.offer(new int[]{0, 0, 0});
        vis[0][0] = true;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1], steps = cur[2];

            if (x == M - 1 && y == N - 1) return steps;

            int jump = A[x][y];

            if (y + jump < N && !vis[x][y + jump]) {
                vis[x][y + jump] = true;
                queue.offer(new int[]{x, y + jump, steps + 1});
            }
            if (x + jump < M && !vis[x + jump][y]) {
                vis[x + jump][y] = true;
                queue.offer(new int[]{x + jump, y, steps + 1});
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        while (T-- > 0) {
            M = in.nextInt();
            N = in.nextInt();
            A = new int[M][N];

            for (int i = 0; i < M; ++i)
                for (int j = 0; j < N; ++j)
                    A[i][j] = in.nextInt();

            System.out.println(BFS());
        }

        in.close();
    }
}
