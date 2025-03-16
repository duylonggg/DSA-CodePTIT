import java.util.*;

public class DSA08045 {
    static final int INF = (int) 1e9;
    static int[] x = new int[3010], y = new int[3010], t = new int[3010];
    static int xz, yz, gz;
    static char[][] arr = new char[6010][6010];
    static int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    static Stack<Integer> sx = new Stack<>(), sy = new Stack<>();

    static int compress(int[] a, int n) {
        System.arraycopy(a, 0, t, 0, n);
        Arrays.sort(t, 0, n);
        int nz = 1;
        for (int i = 1; i < n; i++)
            if (t[i] != t[i - 1])
                t[nz++] = t[i];
        for (int i = 0; i < n; i++)
            a[i] = Arrays.binarySearch(t, 0, nz, a[i]) * 2;
        return nz * 2;
    }

    static void put(int x, int y) {
        if (x < 0 || x >= xz || y < 0 || y >= yz || arr[x][y] == 'X')
            return;
        gz += (arr[x][y] == 'C') ? 1 : 0;
        arr[x][y] = 'X';
        sx.push(x);
        sy.push(y);
    }

    static void DFS(int startx, int starty) {
        put(startx, starty);
        while (!sx.isEmpty()) {
            int x = sx.pop(), y = sy.pop();
            for (int i = 0; i < 4; ++i)
                put(x + dx[i], y + dy[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(), m = sc.nextInt();
            int z = 0;
            x[z] = y[z] = -INF;
            z++;
            x[z] = y[z] = INF;
            z++;

            for (int i = 0; i < 2 * n; ++i)
                x[z] = sc.nextInt();
                y[z] = sc.nextInt();
                z++;

            for (int i = 0; i < m; ++i)
                x[z] = sc.nextInt();
                y[z] = sc.nextInt();
                z++;

            xz = compress(x, z);
            yz = compress(y, z);
            for (int i = 0; i < xz; i++)
                Arrays.fill(arr[i], '.');

            for (int i = 0; i < n; ++i) {
                int a = i * 2 + 2, b = i * 2 + 3;
                int x1 = x[a], y1 = y[a], x2 = x[b], y2 = y[b];
                if (x1 == x2) {
                    if (y1 > y2) {
                        int temp = y1;
                        y1 = y2;
                        y2 = temp;
                    }
                    for (; y1 <= y2; ++y1) arr[x1][y1] = 'X';
                } else {
                    if (x1 > x2) {
                        int temp = x1;
                        x1 = x2;
                        x2 = temp;
                    }
                    for (; x1 <= x2; ++x1) arr[x1][y1] = 'X';
                }
            }

            for (int i = 0; i < m; ++i)
                arr[x[i + 2 * n + 2]][y[i + 2 * n + 2]] = 'C';

            int ans = 0;
            for (int i = 0; i < m; ++i) {
                gz = 0;
                DFS(x[i + 2 * n + 2], y[i + 2 * n + 2]);
                ans = Math.max(ans, gz);
            }
            System.out.println(ans);
        }
        sc.close();
    }
}
