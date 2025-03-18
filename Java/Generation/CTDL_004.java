import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CTDL_004 {
    static List<Integer> array = new ArrayList<>();
    static List<Integer> numb = new ArrayList<>();
    static int count = 0;

    public static void Gen(int start, int N, int K) {
        if (numb.size() == K) {
            ++count;
            return;
        }

        for (int i = start; i < N; ++i) {
            if (!numb.isEmpty() && array.get(i) < numb.get(numb.size() - 1)) {
                continue;
            }
            numb.add(array.get(i));
            Gen(i + 1, N, K);
            numb.remove(numb.size() - 1);
        }
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(), K = in.nextInt();
        for (int i = 1; i <= N; ++i) {
            array.add(in.nextInt());
        }

        Gen(0, N, K);
        System.out.println(count);
            
        in.close();
    }
}
