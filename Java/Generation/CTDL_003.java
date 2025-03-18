import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class CTDL_003 {
    static int N, W, maxC = 0;
    static List<Integer> c = new ArrayList<>(); 
    static List<Integer> a = new ArrayList<>();
    static List<Integer> x = new ArrayList<>();
    static String res = "";

    static void Try(int idx) {
        for (int i = 0; i <= 1; ++i) {
            x.set(idx, i); 

            if (idx == N - 1) {
                int totalW = 0, totalC = 0;
                StringBuilder str = new StringBuilder();

                for (int j = 0; j < N; ++j) {
                    str.append(x.get(j)).append(" ");
                    if (x.get(j) == 1) {
                        totalW += a.get(j);
                        totalC += c.get(j);
                    }
                }

                if (totalW == W && totalC > maxC) {
                    maxC = totalC;
                    res = str.toString();
                }
            } else {
                Try(idx + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        N = in.nextInt();
        W = in.nextInt();

        for (int i = 0; i < N; i++) c.add(in.nextInt());
        for (int i = 0; i < N; i++) a.add(in.nextInt());

        x = new ArrayList<>(Collections.nCopies(N, 0)); 
        Try(0);

        System.out.println(maxC);
        System.out.println(res);

        in.close();
    }
}
