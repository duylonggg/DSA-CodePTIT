import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DSA01009 {
    static int n, k, cnt;
    static List<String> res = new ArrayList<>();

    public static boolean check(String str) {
        int cnt = 0, seg = 0;
        for (int i = 0; i < n; ++i) {
            if (str.charAt(i) == 'A') {
                ++cnt;
                if (cnt > k) return false;
                if (cnt == k) ++seg;
            } else {
                cnt = 0;
            }
        }
        return seg == 1;
    }

    public static void Try(String str) {
        if (str.length() == n) {
            if (check(str)) {
                ++cnt;
                res.add(str);
            }
            return;
        }

        Try(str + "A");
        Try(str + "B");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        k = in.nextInt();

        Try("");

        System.out.println(cnt);
        for (String str : res) {
            System.out.println(str);
        }

        in.close();
    }
}
