import java.util.Arrays;
import java.util.Scanner;

public class DSA01011 {
    static String str;

    public static String gen() {
        int pos = -1;
        char[] arr = str.toCharArray();

        for (int i = arr.length - 2; i >= 0; --i) {
            if (arr[i] < arr[i + 1]) {
                pos = i;
                break;
            }
        }

        if (pos == -1) return "BIGGEST";

        int swapPos = -1;
        for (int i = arr.length - 1; i >= 0; --i) {
            if (arr[i] > arr[pos]) {
                swapPos = i;
                break;
            }
        }

        char temp = arr[pos];
        arr[pos] = arr[swapPos];
        arr[swapPos] = temp;

        Arrays.sort(arr, pos + 1, arr.length);
        return new String(arr);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();

        while (testCases-- > 0) {
            int t = in.nextInt();
            str = in.next();

            System.out.println(t + " " + gen());
        }

        in.close();
    }
}
