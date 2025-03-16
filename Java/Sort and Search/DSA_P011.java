import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class DSA_P011 {
    public static void BFS(char[][] matrix, int n, int m, int start, int end) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        Queue<ArrayList> queue = new ArrayDeque<>();
        queue.offer(new ArrayList<>(Arrays.asList(start, end)));
        matrix[start][end] = '.';

        while (queue.isEmpty() == false) {
            ArrayList<Integer> current = queue.poll();
            int x = current.get(0);
            int y = current.get(1);

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] == '#') {
                    matrix[nx][ny] = '.';
                    queue.offer(new ArrayList<>(Arrays.asList(nx, ny)));
                }
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt(), m = input.nextInt();
        input.nextLine();
        char[][] matrix = new char[n][m];

        for (int i = 0; i < n; ++i) {
            String row = input.nextLine();
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = row.charAt(j);
            }
        }

        int CC = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '#') {
                    BFS(matrix, n, m, i, j);
                    ++CC;
                }
            }
        }

        System.out.println(CC);
        
        input.close();
    }
}
