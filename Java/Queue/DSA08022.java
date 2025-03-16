import java.util.*;

public class DSA08022 {
    public static boolean find(int[] a, int n) {
        Arrays.sort(a);
        Queue<Integer> q0 = new LinkedList<>();
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (a[i] % 3 == 0) q0.add(a[i]);
            else if (a[i] % 3 == 1) q1.add(a[i]);
            else q2.add(a[i]);
        }

        if (sum % 3 == 1) {
            if (!q1.isEmpty()) {
                q1.poll();
            } else if (q2.size() >= 2) {
                q2.poll();
                q2.poll();
            } else {
                return false;
            }
        } else if (sum % 3 == 2) {
            if (!q2.isEmpty()) {
                q2.poll();
            } else if (q1.size() >= 2) {
                q1.poll();
                q1.poll();
            } else {
                return false;
            }
        }

        List<Integer> aux = new ArrayList<>();
        while (!q0.isEmpty()) aux.add(q0.poll());
        while (!q1.isEmpty()) aux.add(q1.poll());
        while (!q2.isEmpty()) aux.add(q2.poll());

        if (!aux.isEmpty()) {
            aux.sort(Collections.reverseOrder());
            for (int num : aux) System.out.print(num);
            System.out.println();
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int test_cases = in.nextInt();

        while (test_cases-- > 0) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = in.nextInt();

            if (!find(a, n)) System.out.println(-1);
        }
        in.close();
    }
}
