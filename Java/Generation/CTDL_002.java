import java.util.*;

public class CTDL_002 {
    public static void Print(ArrayList<ArrayList<Integer>> result) {
        Collections.sort(result, (a, b) -> {
            int i = 0;
            while (i < a.size() && i < b.size()) {
                if (!a.get(i).equals(b.get(i))) {
                    return b.get(i) - a.get(i); 
                }
                ++i;
            }
            return b.size() - a.size(); 
        });

        for (ArrayList<Integer> subset : result) {
            for (int num : subset) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        System.out.println(result.size());
    }

    public static void Gen(int start, int n, int k, int[] arr, ArrayList<Integer> num, ArrayList<ArrayList<Integer>> result, int total) {
        if (total == k) {
            result.add(new ArrayList<>(num));
            return;
        }

        for (int i = start; i < n; ++i) {  
            if (total + arr[i] > k) continue; 

            num.add(arr[i]);
            Gen(i + 1, n, k, arr, num, result, total + arr[i]);
            num.remove(num.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int k = input.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }

        Arrays.sort(arr); 

        ArrayList<Integer> num = new ArrayList<>();
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        Gen(0, n, k, arr, num, result, 0);

        Print(result);

        input.close();
    }
}
