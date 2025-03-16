import java.util.*;

public class DSA08014 {
    static int R, C, unvis;
    static int[][] matrix;
    static final int[] dx = {1, -1, 0, 0};
    static final int[] dy = {0, 0, 1, -1};

    static void BFS(Queue<int[]> q) {
        int res = 0;

        while (!q.isEmpty()) {
            int size = q.size();
            ++res;

            while (size-- > 0) {
                int[] cell = q.poll();
                int x = cell[0], y = cell[1];

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];

                    if (nx >= 0 && nx < R && ny >= 0 && ny < C && matrix[nx][ny] == 1) {
                        --unvis;
                        matrix[nx][ny] = 0;
                        q.add(new int[]{nx, ny});
                    }
                }
            }
        }

        System.out.println(unvis > 0 ? -1 : res - 1);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();

        while (testCases-- > 0) {
            R = in.nextInt();
            C = in.nextInt();
            matrix = new int[R][C];
            unvis = 0;

            Queue<int[]> q = new LinkedList<>();

            for (int r = 0; r < R; ++r) {
                for (int c = 0; c < C; ++c) {
                    matrix[r][c] = in.nextInt();
                    if (matrix[r][c] == 1) ++unvis;
                    else if (matrix[r][c] == 2) {
                        matrix[r][c] = 0;
                        q.add(new int[]{r, c});
                    }
                }
            }

            BFS(q);
        }
        in.close();
    }
}
