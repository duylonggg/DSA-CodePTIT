import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class DSA08025 {
    static int[] dx = {1, 2, 2, 1, -1, -2, -2, -1};
    static int[] dy = {-2, -1, 1, 2, 2, 1, -1, -2};
    
    public static int BFS(String ST, String EN) {
        int sx = ST.charAt(0) - 'a';
        int sy = ST.charAt(1) - '1';
        int ex = EN.charAt(0) - 'a';
        int ey = EN.charAt(1) - '1';    
        int steps = 0;    

        if (ST.equals(EN)) {
            return steps;
        }

        int[][] vis = new int[8][8];
        Queue<int[]> queue = new ArrayDeque<>();
        vis[sx][sy] = 1;
        queue.offer(new int[]{sx, sy, 0});

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            sx = cur[0]; sy = cur[1]; steps = cur[2];

            for (int i = 0; i < 8; ++i) {
                int nx = sx + dx[i];
                int ny = sy + dy[i];

                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && vis[nx][ny] == 0) {
                    if (nx == ex && ny == ey) {
                        return steps + 1;
                    }
                    vis[nx][ny] = 1;
                    queue.offer(new int[]{nx, ny, steps + 1});
                }
            }
        }
        return 0;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        in.nextLine();
        while (Test-- > 0) {
            String string = in.nextLine();
            String ST = string.split(" ")[0];
            String EN = string.split(" ")[1];

            System.out.println(BFS(ST, EN));  
        }
        
        in.close();
    }
}
