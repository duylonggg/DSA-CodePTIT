import java.util.*;

public class DSA08011 {
    static int n;
    static String S, T;

    public static int BFS(Set<String> mySet) {
        mySet.remove(S);
        Queue<Map.Entry<String, Integer>> q = new LinkedList<>();
        q.add(new AbstractMap.SimpleEntry<>(S, 1));

        while (!q.isEmpty()) {
            Map.Entry<String, Integer> front = q.poll();
            String str = front.getKey();
            int steps = front.getValue();

            char[] arr = str.toCharArray();
            for (int j = 0; j < arr.length; ++j) {
                char original = arr[j];

                for (char c = 'A'; c <= 'Z'; ++c) {
                    arr[j] = c;
                    String newStr = new String(arr);
                    arr[j] = original;

                    if (newStr.equals(T)) return steps + 1;
                    if (mySet.remove(newStr)) q.add(new AbstractMap.SimpleEntry<>(newStr, steps + 1));
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();

        while (testCases-- > 0) {
            n = in.nextInt();
            S = in.next();
            T = in.next();
            Set<String> mySet = new HashSet<>();

            while (n-- > 0) mySet.add(in.next());

            System.out.println(BFS(mySet));
        }
        in.close();
    }
}
