import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DSA02008 {
    static int n, k, cnt;
    static List<Integer> numb = new ArrayList<>();
    static boolean[] vis;
    static int[][] v;
    static List<List<Integer>> ans = new ArrayList<>();

    public static void gen(int row, int total) {
        if (numb.size() == n) {
            if (total == k) {
                ans.add(new ArrayList<>(numb));
                cnt++;
            }
            return;
        }

        for (int i = row; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (total + v[i][j] > k) continue;
                if (!vis[j]) {
                    numb.add(j + 1);
                    vis[j] = true;
                    gen(i + 1, total + v[i][j]);
                    vis[j] = false;
                    numb.remove(numb.size() - 1);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        v = new int[n][n];
        vis = new boolean[n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = scanner.nextInt();

        gen(0, 0);

        System.out.println(cnt);
        for (List<Integer> vec : ans) {
            for (int num : vec)
                System.out.print(num + " ");
            System.out.println();
        }

        scanner.close();
    }
}
