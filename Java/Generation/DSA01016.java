import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DSA01016 {
    static int n;
    static List<Integer> numb = new ArrayList<>();

    public static void print() {
        System.out.print("(" + numb.get(0));
        for (int i = 1; i < numb.size(); ++i) {
            System.out.print(" " + numb.get(i));
        }
        System.out.print(") ");
    }

    public static void gen(int start, int total) {
        if (total == n) {
            print();
            return;
        }

        for (int i = start; i > 0; --i) {
            if (total + i > n) continue;
            numb.add(i);
            gen(i, total + i);
            numb.remove(numb.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int test_cases = scanner.nextInt();

        while (test_cases-- > 0) {
            n = scanner.nextInt();
            gen(n, 0);
            System.out.println();
        }

        scanner.close();
    }
}
