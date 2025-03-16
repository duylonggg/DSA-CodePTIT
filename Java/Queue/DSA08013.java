import java.util.*;

public class DSA08013 {
    static int N, x, y, u, v;
    static char[][] matrix;
    static final int[] dx = {1, -1, 0, 0};
    static final int[] dy = {0, 0, 1, -1};

    public static int BFS() {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x, y, 0});
        matrix[x][y] = 'X';

        while (!q.isEmpty()) {
            int[] front = q.poll();
            int curX = front[0], curY = front[1], steps = front[2];

            if (curX == u && curY == v) return steps;

            for (int i = 0; i < 4; ++i) {
                int nx = curX + dx[i], ny = curY + dy[i];

                while (nx >= 0 && nx < N && matrix[nx][curY] == '.') {
                    if (nx == u && curY == v) return steps + 1;
                    if (matrix[nx][curY] == '.') {
                        matrix[nx][curY] = 'X';
                        q.add(new int[]{nx, curY, steps + 1});
                    }
                    nx += dx[i];
                }

                while (ny >= 0 && ny < N && matrix[curX][ny] == '.') {
                    if (curX == u && ny == v) return steps + 1;
                    if (matrix[curX][ny] == '.') {
                        matrix[curX][ny] = 'X';
                        q.add(new int[]{curX, ny, steps + 1});
                    }
                    ny += dy[i];
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();

        while (testCases-- > 0) {
            N = in.nextInt();
            matrix = new char[N][N];

            for (int i = 0; i < N; ++i) {
                String row = in.next();
                matrix[i] = row.toCharArray();
            }

            x = in.nextInt();
            y = in.nextInt();
            u = in.nextInt();
            v = in.nextInt();

            System.out.println(BFS());
        }
        in.close();
    }
}
