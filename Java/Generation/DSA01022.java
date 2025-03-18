import java.util.Arrays;
import java.util.Scanner;

public class DSA01022 {
    static int times;

    static int nextPermutation(int[] nums, int[] finalConfig) {
        times = 1; 

        while (!Arrays.equals(nums, finalConfig)) {
            int n = nums.length;
            int i = n - 2;

            while (i >= 0 && nums[i] >= nums[i + 1]) {
                --i;
            }

            if (i >= 0) { 
                int j = n - 1;
                while (nums[j] <= nums[i]) {
                    --j;
                }
                swap(nums, i, j);
            }

            reverse(nums, i + 1, n - 1);
            times++;
        }
        
        return times;
    }

    static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    static void reverse(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start++, end--);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int Test = in.nextInt();

        while (Test-- > 0) {
            int N = in.nextInt();
            int[] finalConfig = new int[N];
            int[] originConfig = new int[N];

            for (int i = 0; i < N; ++i) {
                originConfig[i] = i + 1;
                finalConfig[i] = in.nextInt();
            }

            System.out.println(nextPermutation(originConfig, finalConfig));
        }

        in.close();
    }
}
