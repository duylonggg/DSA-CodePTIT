import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class DSA08012 {
    static ArrayList<Integer> number = new ArrayList<>();
    
    public static void Gen() {
        Queue<Integer> queue = new ArrayDeque<>();

        for (int i = 1; i <= 5; ++i) queue.offer(i);

        while (!queue.isEmpty()) {
            int num = queue.poll();

            number.add(num);

            if (num >= 10000) {
                continue;
            }

            for (int d = 0; d <= 5; ++d) {
                String strNum = String.valueOf(num);
                if (!strNum.contains(String.valueOf(d))) { 
                    int newNum = Integer.parseInt(strNum + d);
                    queue.offer(newNum);
                }
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Gen();

        int Test = in.nextInt();
        while (Test-- > 0) {
            int L = in.nextInt(), R = in.nextInt(), ans = 0;
            for (int i = 0; i < number.size(); ++i) {
                if (number.get(i) < L) {
                    continue;
                }
                if (number.get(i) > R) {
                    break;
                }
                ++ans;
            }
            System.out.println(ans);
        }
        
        in.close();
    }
}
