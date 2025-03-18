import java.util.*;

public class DSA01006 {
    static void generatePermutations(int[] A, int N, Stack<int[]> stack) {
        stack.push(A.clone()); 

        int pos = N - 2;
        while (pos >= 0 && A[pos] > A[pos + 1]) --pos;

        if (pos == -1) return; 

        int swap_pos = N - 1;
        while (A[swap_pos] < A[pos]) --swap_pos;

        int temp = A[pos];
        A[pos] = A[swap_pos];
        A[swap_pos] = temp;
        Arrays.sort(A, pos + 1, N);

        generatePermutations(A, N, stack); 
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt();

            int[] A = new int[N];
            for (int i = 0; i < N; ++i) {
                A[i] = i + 1;
            }

            Stack<int[]> stack = new Stack<>();
            generatePermutations(A, N, stack);

            while (!stack.isEmpty()) {
                for (int num : stack.pop()) {
                    System.out.print(num);
                }
                System.out.print(" ");
            }

            System.out.println();
        }
        
        in.close();
    }
}
