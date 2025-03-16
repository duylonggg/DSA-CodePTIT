import java.util.*;

public class DSA08015 {
    static int A, B, C;
    static char[][][] rec;
    static final int[] dx = {-1, 1, 0, 0, 0, 0};
    static final int[] dy = {0, 0, -1, 1, 0, 0};
    static final int[] dz = {0, 0, 0, 0, -1, 1};

    static boolean isValid(int z, int x, int y) {
        return (z >= 0 && z < A) && (x >= 0 && x < B) && (y >= 0 && y < C);
    }

    static int BFS(int z, int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{z, x, y, 0});
        rec[z][x][y] = '#';

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int cz = cur[0], cx = cur[1], cy = cur[2], steps = cur[3];

            for (int i = 0; i < 6; ++i) {
                int nz = cz + dz[i];
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (isValid(nz, nx, ny)) {
                    if (rec[nz][nx][ny] == 'E') return steps + 1;
                    if (rec[nz][nx][ny] == '.') {
                        rec[nz][nx][ny] = '#';
                        q.add(new int[]{nz, nx, ny, steps + 1});
                    }
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();

        while (testCases-- > 0) {
            A = in.nextInt();
            B = in.nextInt();
            C = in.nextInt();
            rec = new char[A][B][C];

            int startX = 0, startY = 0, startZ = 0;

            for (int a = 0; a < A; ++a) {
                for (int b = 0; b < B; ++b) {
                    String line = in.next();
                    for (int c = 0; c < C; ++c) {
                        rec[a][b][c] = line.charAt(c);
                        if (rec[a][b][c] == 'S') {
                            startZ = a;
                            startX = b;
                            startY = c;
                        }
                    }
                }
            }

            System.out.println(BFS(startZ, startX, startY));
        }
        in.close();
    }
}
