import java.util.Scanner;

public class DSA01001 {
    public static String nextBit(String bit) {
        int pos = -1;
        char[] arr = bit.toCharArray();

        for (int i = bit.length() - 1; i >= 0; --i) {
            if (arr[i] == '0') {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            return String.join("", java.util.Collections.nCopies(bit.length(), "0"));
        }

        arr[pos] = '1';
        for (int i = pos + 1; i < bit.length(); ++i) {
            arr[i] = '0';
        }

        return new String(arr);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int Test = in.nextInt();
        in.nextLine(); 

        while (Test-- > 0) {
            String bit = in.nextLine();
            System.out.println(nextBit(bit));
        }

        in.close();
    }
}
