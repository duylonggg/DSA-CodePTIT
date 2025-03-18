import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class DSA01028 {
    static int n, k;
    static List<Integer> v = new ArrayList<>(); 
    static List<Integer> numb = new ArrayList<>(); 

    static void print() {
        for (int num : numb) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    static void gen(int start) {
        if (numb.size() == k) {
            print();
            return;
        }

        for (int i = start; i < v.size(); ++i) {
            numb.add(v.get(i));
            gen(i + 1);
            numb.remove(numb.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        n = in.nextInt();
        k = in.nextInt();
        
        Set<Integer> set = new TreeSet<>(); 
        for (int i = 0; i < n; i++) {
            set.add(in.nextInt());
        }
        
        v.addAll(set); 
        gen(0);

        in.close();
    }
}
