import java.util.*;

public class DSA08016 {
    static int[] l1 = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
    static int[] r1 = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
    static int[] l2 = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
    static int[] r2 = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};

    static String change(String str, int[] a) {
        char[] res = new char[10];
        for (int i = 0; i < 10; i++) 
            res[i] = str.charAt(a[i]);
        return new String(res);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCases = sc.nextInt();
        while (testCases-- > 0) {
            Map<String, Integer> vis1 = new HashMap<>(), vis2 = new HashMap<>();
            int ans = Integer.MAX_VALUE;
            StringBuilder A = new StringBuilder();
            String B = "1238004765";

            for (int i = 0; i < 10; i++) {
                int x = sc.nextInt();
                A.append(x);
            }

            Queue<Pair> q1 = new LinkedList<>(), q2 = new LinkedList<>();
            q1.offer(new Pair(A.toString(), 0));
            q2.offer(new Pair(B, 0));

            vis1.put(A.toString(), 0);
            vis2.put(B, 0);

            while (!q1.isEmpty()) {
                Pair p = q1.poll();
                String tmp = p.str;
                int steps = p.steps;

                if (steps >= 14) break;
                
                String newState = change(tmp, l1);
                if (!vis1.containsKey(newState)) {
                    vis1.put(newState, steps + 1);
                    q1.offer(new Pair(newState, steps + 1));
                }
                if (vis2.containsKey(newState)) {
                    ans = Math.min(ans, vis1.get(newState) + vis2.get(newState));
                }

                newState = change(tmp, r1);
                if (!vis1.containsKey(newState)) {
                    vis1.put(newState, steps + 1);
                    q1.offer(new Pair(newState, steps + 1));
                }
                if (vis2.containsKey(newState)) {
                    ans = Math.min(ans, vis1.get(newState) + vis2.get(newState));
                }
            }

            while (!q2.isEmpty()) {
                Pair p = q2.poll();
                String tmp = p.str;
                int steps = p.steps;

                if (steps >= 14) break;
                
                if (vis1.containsKey(tmp)) {
                    ans = Math.min(ans, vis1.get(tmp) + steps);
                }

                String newState = change(tmp, l2);
                if (!vis2.containsKey(newState)) {
                    vis2.put(newState, steps + 1);
                    q2.offer(new Pair(newState, steps + 1));
                }
                if (vis1.containsKey(newState)) {
                    ans = Math.min(ans, vis1.get(newState) + vis2.get(newState));
                }

                newState = change(tmp, r2);
                if (!vis2.containsKey(newState)) {
                    vis2.put(newState, steps + 1);
                    q2.offer(new Pair(newState, steps + 1));
                }
                if (vis1.containsKey(newState)) {
                    ans = Math.min(ans, vis1.get(newState) + vis2.get(newState));
                }
            }

            System.out.println(ans);
        }
        sc.close();
    }

    static class Pair {
        String str;
        int steps;

        Pair(String str, int steps) {
            this.str = str;
            this.steps = steps;
        }
    }
}
